//
//  NSData+OneKitDecorator.h
//  OneKit
//
//  Created by bob on 2019/11/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (OneKitDecorator)

/// 通用包装方法
- (nullable NSData *)rsk_dataByDecorated;

@end

NS_ASSUME_NONNULL_END
