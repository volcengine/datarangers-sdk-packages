//
//  BDAutoTrack+Tracer.h
//  Pods
//
//  Created by bytedance on 2023/12/5.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (Tracer)

/*!
 @abstract 设置 SaaS Tracer 的上报地址

 @param saasTracerHost  输入 SaaS Tracer 上报的 host
 @discussion 一般不需要设置，如果不设置，则默认是云原生的地址：https://gator.volces.com
 */
- (void)setSaasTracerHost:(NSString *)saasTracerHost;

/*!
 @abstract 绑定 SaaS Tracer

 @param saasAppID  输入 SaaS Tracer 的 appID
 @param deviceIDKey  输入绑定当前 deviceID 所用的 key
 @param saasDeviceIDKey  输入绑定 saas tracer 的 deviceID 所用的 key
 @param completion  返回绑定操作的结果
 @discussion 绑定 saas tracer，用于将当前的埋点和 saas 上的 tracer 归因能力联合起来。
 */
- (void)bindSaasTracer:(NSString *)saasAppID
           deviceIDKey:(NSString *)deviceIDKey
       saasDeviceIDKey:(NSString *)saasDeviceIDKey
            completion:(void (^)(BOOL success,NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
