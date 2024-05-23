//
//  BDAutoTrack+OneID.h
//  RangersAppLog
//
//  Created by bytedance on 9/26/22.
//

#import "BDAutoTrack.h"


NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (OneID)



/*!
 @abstract OneID 绑定
 
 @param idmappings  输入用户账户多口径
 e.g.:
 NSDicitionary *idMappings = @{
     @"id_type_1":@"id_type_value_1",
     @"id_type_2":@"id_type_value_2"
 }
 @param completion  返回绑定操作的结果
 
 @discussion 用户多账号体系的绑定、在服务端生成OneID来关联不同账号体系下的同一个用户。
    
 NSDicitionary *idMappings = @{
     @"id_type_1":@"id_type_value_1",
     @"id_type_2":@"id_type_value_2"
 }

 [BDAutoTrack bind:idMappings completion:^(BOOL success,
                       NSError *error) {
 }];
 
 
 
 */
- (void)bind:(NSDictionary<NSString *,NSString *> *)idmappings
  completion:(void (^)(BOOL success,NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
