//
//  BDAutoTrackEncryptionDelegate.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BDAutoTrackEncryptionDelegate <NSObject>
@required
/// Encrypt data for HTTP request. Use your custom encryption method by implementing this protocol and inject it into BDAutoTracker in its initialization.
/// Only takes effect when `logNeedEncypt` is YES.
/// The following data will be passed to this method:
/// (1) All HTTP POST body data
/// (2) Some HTTP query data
/// @param data data before encryption
/// @param error in-out param. Set it when encryption fails.
- (NSData *)encryptData:(NSData *)data error:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
