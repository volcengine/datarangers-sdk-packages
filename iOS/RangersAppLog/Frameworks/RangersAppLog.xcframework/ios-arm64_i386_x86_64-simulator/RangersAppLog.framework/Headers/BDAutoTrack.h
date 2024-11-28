//
//  BDTracker.h
//  Applog
//
//  Created by bob on 2019/1/20.
//

#import <Foundation/Foundation.h>
#import "BDCommonDefine.h"
#import "BDAutoTrackConfig+AppLog.h"
#import "BDAutoTrackAlinkRouting.h"


@class BDAutoTrackConfig;

NS_ASSUME_NONNULL_BEGIN

/*!
 BDAutoTrack日志上报功能的类
 */
@interface BDAutoTrack : NSObject

/*! @abstract
 针对每个AppID 设备唯一rangers Device ID. 非数字，随机字符串，一般情况请不要存储，从SDK接口获取即可。
 @discussion 特别说明，rangersDeviceID是字符串，不是数字
 */
@property (nonatomic, copy, readonly, nullable) NSString *rangersDeviceID;

/*! @abstract
 安装ID，是数字字符串，可以转化为数字。
 */
@property (nonatomic, copy, readonly, nullable) NSString *installID;

/*! @abstract
 数说ID，一般情况下，一个自然人的ssid是一致的。
 */
@property (nonatomic, copy, readonly, nullable) NSString *ssID;

/*! @abstract
 通过[BDAutoTrack setCurrentUserUniqueID:]接口传入到SDK内部的uuid
 */
@property (nonatomic, copy, readonly, nullable) NSString *userUniqueID;

/*! @abstract SDK是否已启动，默认为NO，调用`startTrack`或其便捷方法后为YES。
 */
@property (nonatomic, readonly, assign) BOOL started;

/*! @abstract 初始化的AppID
 */
@property (nonatomic, copy, readonly) NSString *appID;

/*! @abstract 返回SDK版本号。e.g. 6.1.0
 */
+ (NSString *)SDKVersion;

/*! @abstract 是否开启ALink的延迟场景。
 */
@property (nonatomic, readonly, assign) BOOL enableDeferredALink;

+ (instancetype)new __attribute__((unavailable()));
- (instancetype)init __attribute__((unavailable()));
/*! @abstract 初始化方法，初始化一个Track实例
 @param config 初始化配置，AppID AppName Channel是必须的
 @discussion 初始化接口可以重复调用，会返回同一个实例，推荐返回之后，引用住这个实例，下次上报方便使用。
 @result 一个Track实例
 */
+ (nullable instancetype)trackWithConfig:(BDAutoTrackConfig *)config;

/*! @abstract 根据App ID获取一个已经初始化过的Track实例
 @param appID AppID
 @discussion 此接口需要先调用 `[BDAutoTrack trackWithConfig:]`初始化过实例，才能获取到
 @result 一个Track实例
 */
+ (nullable instancetype)trackWithAppID:(NSString *)appID;

/*! @abstract 开始埋点和无埋点上报
 @discussion 需要在`[BDAutoTrack trackWithConfig:]`初始化之后手动调用此方法。调用此方法之前，可以做一些额外的配置
 */
- (void)startTrack;

/*! @abstract userAgent
 @discussion 每次启动SDK的时候设置一次，发生变化的时候设置即可。一般不会发生变化，只需要设置一次即可
 @param userAgent 日志上报HTTP/HTTPS 请求里面的 userAgent
 */
- (void)setUserAgent:(nullable NSString *)userAgent;

/*! @abstract UserUniqueID发生变化时设置
 @discussion 有值，则设置为ID值；登出 请调用 [BDAutoTrack clearUserUniqueID] 或者传 nil
 @discussion SDK会保存，因此只需要变化的时候设置。
 @param uniqueID 用户id，如无特殊需求，请勿传 空字符串 或者 全是空格的字符串
 @return 是否成功设置或登出。
 */
- (BOOL)setCurrentUserUniqueID:(nullable NSString *)uniqueID;



/*! @abstract UserUniqueID发生变化时设置
 @discussion 有值，则设置为ID值；登出 请调用 [BDAutoTrack clearUserUniqueID] 或者传 nil
 @discussion SDK会保存，因此只需要变化的时候设置。
 @param uniqueID 用户id，如无特殊需求，请勿传 空字符串 或者 全是空格的字符串
 @param type   用户id类型
 @return 是否成功设置或登出。
 */
- (BOOL)setCurrentUserUniqueID:(nullable NSString *)uniqueID withType:(nullable NSString *)type;

/*! @abstract 登出 logout
 @discussion 登出 logout
 */
- (void)clearUserUniqueID;

/*! @abstract 手动发起注册请求，一般不需要调用。
 @discussion
 SDK在以下情况会自动调用此方法:
 1. 初始化阶段
 2. 用户通过`setServiceVendor:`方法更改serviceVendor
 3. 用户通过`setCurrentUserUniqueID:`更改userUniqueID
 
 @discussion 用户一般不需要调用此方法，除非因特殊原因需要手动发起注册（一般无必要）
 @param registeringUserUniqueID  要注册的用户ID. 如为nil则使用当前的UserUniqueID.
 @return 是否成功发起注册请求
 */
- (BOOL)sendRegisterRequestWithRegisteringUserUniqueID:(nullable NSString *)registeringUserUniqueID APPLOG_API_AVALIABLE(6.2.3);

/// 同 `sendRegisterRequestWithRegisteringUserUniqueID: nil`
- (BOOL)sendRegisterRequest APPLOG_API_AVALIABLE(5.6.3);

/*! @abstract 设置上报Host地区，有国内、新加坡、美东三个选项
 @discussion 发生变化可以更新，不需要一直重复设置
 @discussion 当新设serviceVendor与旧值不一致时，会重新发起注册请求
 @param serviceVendor 地区
 */
- (void)setServiceVendor:(BDAutoTrackServiceVendor)serviceVendor;

/*! @abstract 设置自定义的URL回调
 @param requestURLBlock 回调block，设置一次即可，不需要多次设置
 @discussion requestURLBlock 会覆盖之前的初始化或者上一次设置的回调，如果为nil会清空回调
 @discussion block在初始化之前 设置一次即可，每次拉取请求都会回调，请勿一直重复设置
 */
- (void)setRequestURLBlock:(nullable BDAutoTrackRequestURLBlock)requestURLBlock;

/*! @abstract 设置自定义的URL回调
 @param requestHostBlock 回调block，设置一次即可，不需要多次设置
 @discussion requestHostBlock 会覆盖之前的初始化或者上一次设置的回调，如果为nil会清空回调
 @discussion requestURLBlock会优先于requestHostBlock
 */
- (void)setRequestHostBlock:(nullable BDAutoTrackRequestHostBlock)requestHostBlock;

/*! @abstract 设置自定义请求通参的回调，即 request body 中 header
 @param commonParamtersBlock 回调block，设置一次即可，不需要多次设置
 @discussion commonParamtersBlock 会覆盖之前的初始化或者上一次设置的回调，如果为nil会清空回调
 @discussion commonParamtersBlock会覆盖默认 request body 中的 header
 */
- (void)setCommonParamtersBlock:(nullable BDAutoTrackCommonParamtersBlock)commonParamtersBlock;

/*! @abstract 地区
 @discussion 如果设置过，会保存值，直到下次改变或者清空
 @discussion 如果没有值，默认会读取 `[[NSLocale currentLocale] objectForKey:NSLocaleCountryCode]`
 @discussion 发生变化时候请调用 `+[BDAutoTrack setAppRegion:]`更新值
 */
- (void)setAppRegion:(nullable NSString *)appRegion;

/*! @abstract 语言
 @discussion 如果设置过，会保存值，直到下次改变或者清空
 @discussion 如果没有值，默认会读取 `[[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode]`
 @discussion 发生变化时候请调用 `+[BDAutoTrack setAppLauguage:]`更新值
 */
- (void)setAppLauguage:(nullable NSString *)appLauguage;

/************** 设置CustomHeader(持久化，会影响下次启动) ***************/
/**
 @abstract 添加自定义上报信息
 @param value 自定义上报value，一般需要传NSString或者数字，或者nil
 @param key 自定义上报key
 @code
 /// 新增或者修改，仅发生变化的时候使用
 [track setCustomHeaderValue:@"male" forKey:@"gender"];
 [track setCustomHeaderValue:@(29) forKey:@"age"];

 /// 删除
 [track removeCustomHeaderValueForKey:@"gender"];
 [track removeCustomHeaderValueForKey:@"age"];
 */
- (void)setCustomHeaderValue:(nullable id)value forKey:(NSString *)key;

/// 将字典中的KV添加进自定义上报信息。已有的键将会被覆盖。
/// @param dictionary 值一般为字符串或数字
- (void)setCustomHeaderWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

/// 删除CustomHeader中的一条KV。
- (void)removeCustomHeaderValueForKey:(NSString *)key;

/************** 设置CustomHeader(非持久化，只作用于本次启动) ***************/
/*! @abstract 添加自定义上报信息
 @param customHeaderBlock 自定义上报信息
 @discussion customHeaderBlock 一次App启动设置一次即可；App重启需要重新设置，因为SDK不会保存上次设置的值；会覆盖之前的初始化的或者上一次设置的，如果为nil会清空回调
 @discussion block在初始化之前设置一次即可，每次都会回调，不会把block返回参数保存，而导致获取不到变化的值，请勿一直重复设置
 
 [track setCustomHeaderBlock:^NSDictionary<NSString *,id> * _Nonnull{
    return @{@"gender":[UserInfo GetGender],
           @"age":@([UserInfo GetAge]),
           };
 }];
 */
- (void)setCustomHeaderBlock:(nullable BDAutoTrackCustomHeaderBlock)customHeaderBlock;


/*!
 @abstract 添加激活流自定义上报信息
 @param customParamsBlock 自定义上报信息回调函数
       NSDictionary.allValues 都会被转换为字符串
       [NSNull null] 会被转换为空字符串
 @discussion block 在 startTrack 之前设置
 
 [track setActiveCustomParamsBlock:^NSDictionary<NSString *,id> * _Nonnull{
    return @{
            @"gender":[UserInfo GetGender],
            @"age":@([UserInfo GetAge])
          };
 }];
 */
- (void)setActiveCustomParamsBlock:(NSDictionary<NSString *,id> * (^)(void))customParamsBlock;

/*! @abstract 日志上报
 @param event 事件名称，不能为nil或空字符串
 @param params 事件参数。可以为空或者nil，但是param如果非空，需要可序列化成json
 @discussion params 请参考文档中的日志格式要求，或者使用 [NSJSONSerialization isValidJSONObject:] 来检查params是否可序列化
 @result 是否成功，如果失败，则表示此日志不会被上报。原因是无法序列化。
 */
- (BOOL)eventV3:(NSString *)event params:(nullable NSDictionary *)params;

/*! @abstract 日志上报
@param event 事件名称，不能为nil或空字符串
@result 是否成功
*/
- (BOOL)eventV3:(NSString *)event;

#pragma mark - Event Handler

/*! @abstract 修改数据的属性
 
 @param handler 传入事件名以及事件自定义数据，允许进行自定义属性进行修改以及删除。返回一个EventPolicy值 ， BDAutoTrackEventPolicyAccept 表示事件被记录，BDAutoTrackEventPolicyDeny 表示事件会被丢弃。
 @param types 设置需要进行过滤的事件类型，多次事件类型采用 BDAutoTrackDataTypeUserEvent ｜BDAutoTrackDataTypeProfile 的方式设置
 @discussion properties 请使用 [NSJSONSerialization isValidJSONObject:] 来校验。单一Tracker实例只会维护EventHandler，多次调用会覆盖之前的逻辑。

 */
- (void)setEventHandler:(BDAutoTrackEventHandler)handler
               forTypes:(BDAutoTrackDataType)types;

#pragma mark - Session
/*! @abstract 获取当前的 sessionID
 @result 返回当前的 sessionID
 @discussion sessionID 在 App 启动 & 切 App 前台时刷新
 */
- (NSString *)currentSessionID;

#pragma mark - ABTest

/*! @abstract 获取ABTest的配置值
 @param key ABTest的key
 @param defaultValue 默认值，如果没有配置，或者未开启ABTest则返回默认值
 @discussion 未开启ABTest或者ABTest配置了默认值，都是返回默认值，因此建议监听BDAutoTrackNotificationABTestSuccess来判断是否开启了ABTest
 @discussion 通过此接口读取会触发曝光统计
 @result 返回ABTest的配置值
 */
- (nullable id)ABTestConfigValueForKey:(NSString *)key defaultValue:(nullable id)defaultValue;

/*! @abstract 本地缓存已加载时同`ABTestConfigValueForKey:defaultValue:`。本地缓存未加载时将阻塞等待其加载完成。
 @discussion 本地缓存一般在初始化后30-100ms内加载完成。
 此方法旨在便于业务在初始化后立即获取到已缓存的AB实验数据，可能耗时较长。
 */
- (nullable id)ABTestConfigValueSyncForKey:(NSString *)key defaultValue:(nullable id)defaultValue;

/*! @abstract 获取ABTest 额外的vids
@param versions 额外的vids。格式比如 @"1,2,3"。是逗号（英文）分割，逗号之间是数字
@discussion 如果要清空上次设置，直接传nil；每次设置都会覆盖上次设置
*/
- (void)setExternalABVersion:(nullable NSString *)versions;

/*! @abstract 获取ABTest相关配置
@result 返回ABTest的vids值
 @discussion 此值不需要设置到上报的event中，SDK会自动给每个event添加
 */
- (nullable NSString *)abVids;

/*! @abstract 获取ABTest相关配置
 @result 返回ABTest的所有的vids值
 @discussion 此接口不会触发曝光，可以随意读取
 */
- (nullable NSString *)allAbVids;

/*! @abstract 获取ABTest相关配置
@result 返回ABTest曝光过的的vids值
 @discussion 此值不需要设置到上报的event中，SDK会自动给每个event添加
 */
- (nullable NSString *)abExposedVids;

/*! @abstract 获取ABTest相关配置
 @result 返回ABTest的所有的Configs值
 @discussion 此接口不会触发曝光，可以随意读取。
 @discussion 如果正常为了做实验，请勿使用此接口，请使用-[BDAutoTrack ABTestConfigValueForKey:defaultValue:]接口
 */
- (nullable NSDictionary *)allABTestConfigs;

/// `allABTestConfigs` version 2. Align with web and Android.
/// return raw key-value in server response.
- (nullable NSDictionary *)allABTestConfigs2;


/*! @abstract 手动触发拉取 ABTest Configs 请求
 @discussion 正常冷启动、切换用户、定时10分钟会自动请求 ABTest Configs。
 此方法可以手动触发一次 ABTest Configs 请求
 */
- (void)pullABTestConfigs APPLOG_API_DEPRECATED_WITH_REPLACEMENT("use pullABTestConfigs:completion: Instead");

/*! @abstract 手动触发拉取 ABTest Configs 请求
    @param timeout 请求超时时间
    @discussion 手动触发会有频控，每10s内允许请求一次
 */
- (void)pullABTestConfigs:(NSTimeInterval)timeout
               completion:(void (^)(BOOL success, NSError * _Nullable error))completion;


#pragma mark - ALink
/* 如果你的应用不使用ALink功能，可忽略此节。 */
/*! 设置路由代理对象。路由代理对象负责接受SDK回传的路由数据，并根据数据做页面路由。
 @discussion 如应用不使用ALink功能，可忽略。
 */
- (void)setALinkRoutingDelegate:(id<BDAutoTrackAlinkRouting>)ALinkRoutingDelegate;

/*! 此方法内部会判断参数是否为有效的ALink。如果是则会异步请求路由数据，并回传给路由代理对象。
 @discussion 如果你的应用没有使用UIScene，你应该在`application: openURL: options:`和`application: continueUserActivity: restorationHandler:`处调用此方法。
 如果你的应用使用了UIScene，请参考没有使用UIScene的情况，并结合你应用的具体情况，判断在何处调用此方法，一般可以在`scene: openURLContexts:`和`scene:continueUserActivity:`处调用此方法。
 如应用不使用ALink功能，可忽略。
 @param ALinkURL 深度链接URL。可以是Universal Link 或 Custom URL Scheme
 @return 是否是有效的ALink
 @code
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
     if([BDAdapter handleURL:url scene:nil]) {
         return YES;
     }
     if ([BDAutoTrack continueALinkActivityWithURL:url]) {
         return YES;
     }

     /// your handle code

     return NO;
 }

 - (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler {
     if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
         NSURL *universalLinkURL = userActivity.webpageURL;
         if ([universalLinkURL.host isEqualToString:@"myapphost.com"]) {
             // 如你的应用有多个Universal Links域名，可以先判断是否是其他域名。
             return YES;
         }
         else if ([BDAutoTrack continueALinkActivityWithURL:userActivity.webpageURL]) {  // 多半是ALink，交给AppLog SDK来处理。如果不是ALink，SDK也会返回NO。
             return YES;
         }
         return NO;
     }
     
     return YES;
 }
 */
- (BOOL)continueALinkActivityWithURL:(NSURL *)ALinkURL;


#pragma mark - Location

+ (void)setGPSLocation:(enum BDAutoTrackGeoCoordinateSystem)geoCoordinateSystem longitude:(double)longitude latitude:(double)latitude;


#pragma mark - DurationEvent
/// 时长事件统计开始时调用
/// - Parameter eventName: 事件名称
- (void)startDurationEvent:(NSString *)eventName;

/// 时长事件统计暂停时调用
/// - Parameter eventName: 事件名称
- (void)pauseDurationEvent:(NSString *)eventName;

/// 时长事件统计恢复时调用
/// - Parameter eventName: 事件名称
- (void)resumeDurationEvent:(NSString *)eventName;

/// 时长事件统计停止时调用
/// - Parameters:
///   - eventName: 事件名称
///   - properties: 事件参数
- (void)stopDurationEvent:(NSString *)eventName properties:(NSDictionary *)properties;

/// 时长事件统计停止时调用，支持自定义事件名称，支持不同 key 最终产生相同事件名的事件
/// - Parameters:
///   - eventName: 事件名称
///   - properties: 事件参数
///   - customName: 自定义事件名称，设置后会替代eventName作为最终上传字段；customName为空时，等同于调用- (void)stopDurationEvent: properties:
- (void)stopDurationEvent:(NSString *)eventName properties:(NSDictionary *)properties customName:(NSString *)customName;

#pragma mark - main app only

/*! @abstract 主动触发上报。SDK有频率限制，每10s最多可以触发一次
*/
- (void)flush;

/*! @abstract
 *  清除所有数据
 *
 *  @discussion
 *  调用API会清除所有的缓存的数据，包括内存以及数据文件，请务必谨慎使用！！
 *
 */
- (void)clearAllEvent;


#pragma mark - private API

/*! @abstract 调用用户激活接口。一般情况下，请勿调用，除非知晓调用可能的问题。
 */
- (void)activeUser;

@end

#pragma mark - Special

@interface BDAutoTrack (SharedSpecial)

+ (BOOL)eventV3:(NSString *)event params:(nullable NSDictionary *)params specialParams:(NSDictionary *)specialParams;

+ (BOOL)customEvent:(NSString *)category params:(NSDictionary *)params;

@end




@interface BDAutoTrack (API_DEPRECATED)

- (nullable NSString *)abVidsSync APPLOG_API_DEPRECATED_WITH_REPLACEMENT("use -abVids instead");

- (nullable NSString *)allAbVidsSync APPLOG_API_DEPRECATED_WITH_REPLACEMENT("use -allAbVids instead");

/*! @abstract 本地缓存已加载时同`allABTestConfigs`。本地缓存未加载时将阻塞等待其加载完成。
 @discussion 本地缓存一般在初始化后30-100ms内加载完成。
 此方法旨在便于业务在初始化后立即获取到已缓存的AB实验数据，可能耗时较长。
 */
- (nullable NSDictionary *)allABTestConfigsSync  APPLOG_API_DEPRECATED_WITH_REPLACEMENT("use -allABTestConfigs instead");

@end



NS_ASSUME_NONNULL_END

/// 单例的类方法
#import "BDAutoTrack+SharedInstance.h"
#import "BDAutoTrack+Profile.h"
