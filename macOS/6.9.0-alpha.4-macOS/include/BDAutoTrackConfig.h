//
//  BDAutoTrackConfig.h
//  RangersAppLog
//
//  Created by bob on 2020/3/25.
//

#import <Foundation/Foundation.h>
#import "BDCommonDefine.h"
#import "BDAutoTrackEncryptionDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackConfig : NSObject

/*! @abstract channel默认 @"App Store", Release版本只有 @"App Store"， debug版本可以任意设置. */
@property (nonatomic, copy) NSString *channel;

/*! @abstract 申请appID时候填写的英文名称 */
@property (nonatomic, copy, nullable) NSString *appName;

/*! @abstract AppID，非空，必须设置 */
@property (nonatomic, copy) NSString *appID;

/*! @abstract 默认国内,初始化时一定要传正确的值
 @discussion 发生变化时候请调用 `+[BDAutoTrack setServiceVendor:]`更新值
 @discussion 会影响注册和日志上报。所以如果发生变化后，下次启动初始化请传入正确的值
 */
@property (nonatomic, copy) BDAutoTrackServiceVendor serviceVendor;

/*! @abstract 如有初始的UserUniqueID，可以在此设置。
 @discussion 此属性解决了一些业务需要在SDK初始化时就设置UserUniqueID的需求。
 @discussion Note: 在应用第一次启动时，SDK会在初始化时设置UserUniqueID为此属性的值。
 后续用户登出后，UserUniqueID会变为nil，此时SDK不会重新把UserUniqueID设置为此属性的值。
 */
@property (nonatomic, copy, nullable) NSString *initialUserUniqueID;

/*! @abstract 是否开启 WKWebView 的 H5 打通功能，开启后，若WebView页面的JS AppLog SDK侧也配置开启H5Bridge，则H5 埋点将可以从 Native 端上报。默认关闭。
 */
@property (nonatomic) BOOL enableH5Bridge;

/*! @abstract 是否开启ALink的延迟场景。默认关闭。 */
@property (nonatomic) BOOL enableDeferredALink;

/*! H5Bridge功能域名白名单。只有名单中的页面会开启Bridge。支持通配符。
 * @code
 * config.H5BridgeAllowedDomainPatterns = @[@"*.myapp.com", @"myapp.com"];
*/
@property (nonatomic, copy) NSArray<NSString *> *H5BridgeAllowedDomainPatterns;

/*! 当切换用户时，清除AB Versions缓存。默认为开(YES)。
 */
@property (nonatomic) BOOL clearABCacheOnUserChange;

/*! 应用启动选项 */
@property (nonatomic, readonly) NSDictionary<id, id> *launchOptions;

/*! @abstract Define custom encryption method (or custom encryption key)
 @discussion SDK不持有该对象。传入前须确保该对象在SDK使用期间不被释放，请勿传入临时对象。
 SDK will not hold the delegate. Please ensure the delegate's liveness during SDK's usage. Do not pass temporary object.
 */
@property (nonatomic, weak) id<BDAutoTrackEncryptionDelegate> encryptionDelegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*! @abstract 根据App ID获取一个config
@param appID 注册应用时获取的AppID
@param launchOptions 应用启动选项，一般直接传入`application:didFinishLaunchingWithOptions:`的`launchOptions`参数即可
*/
+ (instancetype)configWithAppID:(NSString *)appID launchOptions:(nullable NSDictionary<id,id> *)launchOptions APPLOG_API_AVALIABLE(6.0.0);

/*! @abstract 根据App ID获取一个config
@param appID AppID
@result 一个config实例, 其他参数非必填，或者有默认值，可以直接通过setter 设置
@discussion 如果您要使用ALink功能，请勿使用此API。此API已过时，后续版本将下掉，请及时使用新API。
*/
+ (instancetype)configWithAppID:(NSString *)appID APPLOG_API_DEPRECATED_WITH_REPLACEMENT("configWithAppID:launchOptions:");

/*! @abstract 根据App ID获取一个config
@param appID AppID
@result 一个config实例, 此config默认设置了不会激活和拉取settings。可用于第三方SDK需要上报一些事件，但是不需要激活等
*/
+ (instancetype)configWithSecondAppID:(NSString *)appID;

@end

NS_ASSUME_NONNULL_END
