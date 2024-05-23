#ifndef APPLOG_PRI_
#define APPLOG_PRI_

#include <stdint.h>
#include <stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 示例
 void* dataIn = xxx;
 size_t data_size = xxx;

 size_t bufferSize = applog_decorated_buffer_min_size(data_size);
 uint8_t *buffer = malloc(sizeof(uint8_t) * bufferSize);

 applog_decorated(dataIn, data_size, buffer, &bufferSize)
 if (bufferSize > 0)
 {
    // 加密成功，加密数据为 buffer[0 -> bufferSize]
 }
 else
 {
    // 加密失败
 }
 */

#define applog_decorated_buffer_min_size(x) (x + 6 + 32 + 64 + 16 - x % 16)


/// buffer_size = data_size + 6 + 32 + 64 + 16
void applog_decorated_private(const void* dataIn,
                              const size_t data_size,
                              uint8_t *buffer_out,
                              size_t *buffer_size);

#ifdef  __cplusplus
}
#endif

#endif

