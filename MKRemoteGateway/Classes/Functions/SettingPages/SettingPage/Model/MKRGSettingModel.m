//
//  MKRGSettingModel.m
//  MKRemoteGateway_Example
//
//  Created by aa on 2023/2/4.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKRGSettingModel.h"

#import "MKMacroDefines.h"

#import "MKRGDeviceModeManager.h"

#import "MKRGMQTTInterface.h"

#import "MKMacroDefines.h"

#import "MKRGDeviceModeManager.h"

#import "MKRGMQTTInterface.h"

@interface MKRGSettingModel ()

@property (nonatomic, strong)dispatch_queue_t readQueue;

@property (nonatomic, strong)dispatch_semaphore_t semaphore;

@end

@implementation MKRGSettingModel

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self readAdvStatus]) {
            [self operationFailedBlockWithMsg:@"Read Data Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            sucBlock();
        });
    });
}

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (!ValidStr(self.advTime) || [self.advTime integerValue] < 1 || [self.advTime integerValue] > 10) {
            [self operationFailedBlockWithMsg:@"Params error" block:failedBlock];
            return;
        }
        if (![self configAdvStatus]) {
            [self operationFailedBlockWithMsg:@"Config Data Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            sucBlock();
        });
    });
}

#pragma mark - interface
- (BOOL)readAdvStatus {
    __block BOOL success = NO;
    [MKRGMQTTInterface rg_readBleAdvStatusWithMacAddress:[MKRGDeviceModeManager shared].macAddress topic:[MKRGDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        self.advIsOn = ([returnData[@"data"][@"adv_state"] integerValue] == 1);
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

- (BOOL)configAdvStatus {
    __block BOOL success = NO;
    [MKRGMQTTInterface rg_configBleAdvStatus:self.advIsOn advTime:[self.advTime integerValue] macAddress:[MKRGDeviceModeManager shared].macAddress topic:[MKRGDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

#pragma mark - private method

- (void)operationFailedBlockWithMsg:(NSString *)msg block:(void (^)(NSError *error))block {
    moko_dispatch_main_safe(^{
        NSError *error = [[NSError alloc] initWithDomain:@"Settings"
                                                    code:-999
                                                userInfo:@{@"errorInfo":msg}];
        block(error);
    });
}

#pragma mark - getter
- (dispatch_semaphore_t)semaphore {
    if (!_semaphore) {
        _semaphore = dispatch_semaphore_create(0);
    }
    return _semaphore;
}

- (dispatch_queue_t)readQueue {
    if (!_readQueue) {
        _readQueue = dispatch_queue_create("settingsParamsQueue", DISPATCH_QUEUE_SERIAL);
    }
    return _readQueue;
}

@end
