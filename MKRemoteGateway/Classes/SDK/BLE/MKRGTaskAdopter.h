//
//  MKRGTaskAdopter.h
//  MKRemoteGateway_Example
//
//  Created by aa on 2023/1/29.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const mk_rg_totalNumKey;
extern NSString *const mk_rg_totalIndexKey;
extern NSString *const mk_rg_contentKey;

@class CBCharacteristic;
@interface MKRGTaskAdopter : NSObject

+ (NSDictionary *)parseReadDataWithCharacteristic:(CBCharacteristic *)characteristic;

+ (NSDictionary *)parseWriteDataWithCharacteristic:(CBCharacteristic *)characteristic;

@end

NS_ASSUME_NONNULL_END
