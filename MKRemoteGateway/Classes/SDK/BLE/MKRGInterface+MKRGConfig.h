//
//  MKRGInterface+MKRGConfig.h
//  MKRemoteGateway_Example
//
//  Created by aa on 2023/1/29.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKRGInterface.h"

#import "MKRGSDKNormalDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKRGInterface (MKRGConfig)

#pragma mark ******************Custom parameter configuration*********************

#pragma mark *********************System Params************************

/// The device enter STA mode.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_enterSTAModeWithSucBlock:(void (^)(void))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure NTP server domain name.
/// @param host 0~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configNTPServerHost:(NSString *)host
                      sucBlock:(void (^)(void))sucBlock
                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the current time zone to the device.(MK107)
/// @param timeZone Time Zone(-12~12)
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configTimeZone:(NSInteger)timeZone
                 sucBlock:(void (^)(void))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************MQTT Params************************
/// Configure the domain name of the MQTT server.
/// @param host 1~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerHost:(NSString *)host
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the port number of the MQTT server.
/// @param port 0~65535
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerPort:(NSInteger)port
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure Client ID of the MQTT server.
/// @param clientID 1~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configClientID:(NSString *)clientID
                 sucBlock:(void (^)(void))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the user name for the device to connect to the server. If the server passes the certificate or does not require any authentication, you do not need to fill in.
/// @param userName 0~256 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerUserName:(NSString *)userName
                       sucBlock:(void (^)(void))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the password for the device to connect to the server. If the server passes the certificate or does not require any authentication, you do not need to fill in.
/// @param password 0~256 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerPassword:(NSString *)password
                       sucBlock:(void (^)(void))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure clean session of the  MQTT server.
/// @param clean clean
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerCleanSession:(BOOL)clean
                           sucBlock:(void (^)(void))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure Keep Alive of the MQTT server.
/// @param interval 10s~120s.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerKeepAlive:(NSInteger)interval
                        sucBlock:(void (^)(void))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure Qos of the MQTT server.
/// @param mode mode
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configServerQos:(mk_rg_mqttServerQosMode)mode
                  sucBlock:(void (^)(void))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the subscription topic of the device.
/// @param subscibeTopic 1~128 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configSubscibeTopic:(NSString *)subscibeTopic
                      sucBlock:(void (^)(void))sucBlock
                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the publishing theme of the device.
/// @param publishTopic 1~128 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configPublishTopic:(NSString *)publishTopic
                     sucBlock:(void (^)(void))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the switch state of MQTT LWT.
/// @param isOn isOn
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configLWTStatus:(BOOL)isOn
                  sucBlock:(void (^)(void))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure Qos of the MQTT LWT.
/// @param mode mode
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configLWTQos:(mk_rg_mqttServerQosMode)mode
               sucBlock:(void (^)(void))sucBlock
            failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the retain state of MQTT LWT.
/// @param isOn isOn
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configLWTRetain:(BOOL)isOn
                  sucBlock:(void (^)(void))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the topic of MQTT LWT.
/// @param topic 1~128 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configLWTTopic:(NSString *)topic
                 sucBlock:(void (^)(void))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the message of MQTT LWT.
/// @param payload 1~128 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configLWTPayload:(NSString *)payload
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the device tcp communication encryption method.
/// @param mode mode
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configConnectMode:(mk_rg_connectMode)mode
                    sucBlock:(void (^)(void))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the root certificate of the MQTT server.
/// @param caFile caFile
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configCAFile:(NSData *)caFile
               sucBlock:(void (^)(void))sucBlock
            failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure client certificate.
/// @param cert cert
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configClientCert:(NSData *)cert
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure client private key.
/// @param privateKey privateKey
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configClientPrivateKey:(NSData *)privateKey
                         sucBlock:(void (^)(void))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;


#pragma mark *********************WIFI Params************************

/// WIFI Security.
/// @param security security
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFISecurity:(mk_rg_wifiSecurity)security
                     sucBlock:(void (^)(void))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure SSID of WIFI.
/// @param ssid 1~32 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFISSID:(NSString *)ssid
                 sucBlock:(void (^)(void))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure password of WIFI.(WIFI Security is persional.)
/// @param password 0~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIPassword:(NSString *)password
                     sucBlock:(void (^)(void))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// WIFI EAP Type.(WIFI Security is enterprise.)
/// @param eapType eapType
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIEAPType:(mk_rg_eapType)eapType
                    sucBlock:(void (^)(void))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// WIFI EAP username.(EAP Type is PEAP-MSCHAPV2 or  TTLS-MSCHAPV2.)
/// @param username 0~32 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIEAPUsername:(NSString *)username
                        sucBlock:(void (^)(void))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// WIFI EAP password.(EAP Type is PEAP-MSCHAPV2 or  TTLS-MSCHAPV2.)
/// @param password 0~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIEAPPassword:(NSString *)password
                        sucBlock:(void (^)(void))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// WIFI EAP Domain ID.(EAP Type is TLS.)
/// @param domainID 0~64 character ascii code.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIEAPDomainID:(NSString *)domainID
                        sucBlock:(void (^)(void))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Whether the server verification is enabled on WIFI.(EAP Type is PEAP-MSCHAPV2 or  TTLS-MSCHAPV2.)
/// @param verify verify
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIVerifyServerStatus:(BOOL)verify
                               sucBlock:(void (^)(void))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the root certificate of the WIFI.(WIFI Security is enterprise.)
/// @param caFile caFile
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFICAFile:(NSData *)caFile
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the client certificate of the WIFI.(EAP Type is TLS.)
/// @param cert cert
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIClientCert:(NSData *)cert
                       sucBlock:(void (^)(void))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the client private key of the WIFI.(EAP Type is TLS.)
/// @param privateKey privateKey
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configWIFIClientPrivateKey:(NSData *)privateKey
                             sucBlock:(void (^)(void))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// DHCP Status.
/// @param isOn isOn
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configDHCPStatus:(BOOL)isOn
                   sucBlock:(void (^)(void))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;

/// IP Information.
/// @param ip e.g.(@"47.104.81.55")
/// @param mask e.g.(@"255.255.255.255")
/// @param gateway e.g.(@"255.255.255.1")
/// @param dns e.g.(@"47.104.81.55")
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configIpAddress:(NSString *)ip
                      mask:(NSString *)mask
                   gateway:(NSString *)gateway
                       dns:(NSString *)dns
                  sucBlock:(void (^)(void))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************Filter Params************************

/// The device will uplink valid ADV data with RSSI no less than rssi dBm.
/// @param rssi -127 dBm ~ 0 dBm.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configRssiFilterValue:(NSInteger)rssi
                        sucBlock:(void (^)(void))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Broadcast content filtering logic.
/// @param relationship relationship
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configFilterRelationship:(mk_rg_filterRelationship)relationship
                           sucBlock:(void (^)(void))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Filtered list of mac addresses.
/// @param macList You can set up to 10 filters.1-6 Bytes.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configFilterMACAddressList:(NSArray <NSString *>*)macList
                             sucBlock:(void (^)(void))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Filtered list of Adv Name.
/// @param nameList You can set up to 10 filters.1-20 Characters.
/// @param sucBlock Success callback
/// @param failedBlock Failure callback
+ (void)rg_configFilterAdvNameList:(NSArray <NSString *>*)nameList
                          sucBlock:(void (^)(void))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
