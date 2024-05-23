//
//  NSData+OKSecurity.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! @abstract AES 加密 key size类型
 @discussion key size要和传入的key符合
*/
typedef NS_ENUM(NSInteger, OKAESKeySize) {
    OKAESKeySizeAES128 = 0x10, /// 对应key的byte是16字节
    OKAESKeySizeAES192 = 0x18, /// 对应key的byte是24字节
    OKAESKeySizeAES256 = 0x20, /// 对应key的byte是32字节
};

@interface NSData (OKSecurity)


/*! @abstract AES 加密方法
 @param key 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param iv 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式。iv要求16字节
 @result 加密结果，失败则返回nil
 @discussion key和keySize要对应
*/
- (nullable NSData *)ok_aesEncryptWithkey:(NSString *)key
                                   keySize:(OKAESKeySize)keySize
                                        iv:(nullable NSString *)iv;

/*! @abstract AES 加密方法
 @param keyData 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param ivData 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式。iv要求16字节
 @result 加密结果，失败则返回nil
 @discussion key和keySize要对应
*/
- (nullable NSData *)ok_aesEncryptWithkeyData:(NSData *)keyData
                                       keySize:(OKAESKeySize)keySize
                                        ivData:(nullable NSData *)ivData;

/*! @abstract AES 解密方法
 @param key 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param iv 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式。iv要求16字节
 @result 解密结果，失败则返回nil
 @discussion key和keySize要对应
*/
- (nullable NSData *)ok_aesDecryptwithKey:(NSString *)key
                                   keySize:(OKAESKeySize)keySize
                                        iv:(nullable NSString *)iv;

/*! @abstract AES 解密方法
 @param keyData 加密的key，这个需要和keySize对应的byte一致。如果过长，会截断；如果过短，默认用0填充
 @param keySize 参考枚举值OKAESKeySize三种选项
 @param ivData 如果 iv是nil，则使用EBC模式，不为nil则使用CBC模式。iv要求16字节
 @result 解密结果，失败则返回nil
 @discussion key和keySize要对应
*/
- (nullable NSData *)ok_aesDecryptwithKeyData:(NSData *)keyData
                                       keySize:(OKAESKeySize)keySize
                                        ivData:(nullable NSData *)ivData;

@end

NS_ASSUME_NONNULL_END
