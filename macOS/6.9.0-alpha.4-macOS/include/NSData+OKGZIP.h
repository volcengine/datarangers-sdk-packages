//
//  NSData+OKGZIP.h
//  OneKit
//
//  Created by bob on 2020/6/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (OKGZIP)

/// GZIP
- (nullable NSData *)ok_dataByGZipCompressingWithError:(NSError * __autoreleasing *)error;
- (BOOL)ok_isGzipCompressedData;
- (nullable NSData *)ok_dataByGZipDecompressingDataWithError:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
