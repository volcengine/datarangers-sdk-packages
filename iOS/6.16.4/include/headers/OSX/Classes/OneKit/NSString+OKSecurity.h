//
//  NSString+OKSecurity.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import "NSData+OKSecurity.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSString (OKSecurity)

/*! @abstract AES 加密方法
 @param key 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param iv 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式
 @result 加密结果
 @discussion key和keySize要对应
 @discussion aes加密后的data不一定能转成正常的字符串，因此需要经过base64编码
*/
- (nullable NSString *)ok_aesEncryptWithkey:(NSString *)key
                                     keySize:(OKAESKeySize)keySize
                                          iv:(nullable NSString *)iv;

/*! @abstract AES 解密方法
 @param key 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param iv 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式
 @result 解密结果，失败则返回nil
 @discussion aes的密文data不一定能转成正常的字符串，因此需要经过base64编码。故而解密会经过base64解码
*/
- (nullable NSString *)ok_aesDecryptwithKey:(NSString *)key
                                     keySize:(OKAESKeySize)keySize
                                          iv:(nullable NSString *)iv;
@end

NS_ASSUME_NONNULL_END
