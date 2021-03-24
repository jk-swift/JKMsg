//
//  ALogService.h
//  ALog
//
//  Created by Long on 2021/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 日志级别
typedef enum {
    ALogLevelVerbose = 0,
    ALogLevelDebug, // Detailed information on the flow through the system.
    ALogLevelInfo,  // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    ALogLevelWarn,  // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    ALogLevelError, // Other runtime errors or unexpected conditions.
    ALogLevelTest
} ALogLevel;

/// 日志类型
typedef enum {
    ALogTypeNormal  = 0,
    ALogTypeApi     = 1
} ALogType;

/**
 日志配置类
 */
@interface ALogOptions : NSObject

@property (nonatomic, assign)   ALogLevel   level;
@property (nonatomic, assign)   NSString    *path;
@property (nonatomic, assign)   NSString    *filePrefix;
@property (nonatomic, assign)   NSString    *moduleName;

@end

/**
 日志服务类
 */
@interface ALogService: NSObject

+ (ALogService *)shared;

- (void)setupWithOptions:(ALogOptions *)options;

- (void)logWithLevel:(ALogLevel)level tag:(NSString *)tag type:(ALogType)type line:(int32_t)line desc:(NSString *)format, ...;

@end
/**
 日志打印快捷方法
 */
#define ALogDebug(frmt, ...)    [[ALogService shared] logWithLevel:ALogLevelDebug tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeNormal line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ALogInfo(frmt, ...)     [[ALogService shared] logWithLevel:ALogLevelInfo tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeNormal line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ALogWarn(frmt, ...)     [[ALogService shared] logWithLevel:ALogLevelWarn tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeNormal line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ALogError(frmt, ...)    [[ALogService shared] logWithLevel:ALogLevelError tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeNormal line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ALogTest(frmt, ...)     [[ALogService shared] logWithLevel:ALogLevelTest tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeNormal line:__LINE__ desc:(frmt), ## __VA_ARGS__];

/**
 接口日志打印快捷方法
 */
#define ApiLogDebug(frmt, ...)    [[ALogService shared] logWithLevel:ALogLevelDebug tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeApi line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ApiLogInfo(frmt, ...)     [[ALogService shared] logWithLevel:ALogLevelInfo tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeApi line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ApiLogWarn(frmt, ...)     [[ALogService shared] logWithLevel:ALogLevelWarn tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeApi line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ApiLogError(frmt, ...)    [[ALogService shared] logWithLevel:ALogLevelError tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeApi line:__LINE__ desc:(frmt), ## __VA_ARGS__];
#define ApiLogTest(frmt, ...)    [[ALogService shared] logWithLevel:ALogLevelTest tag:[NSString stringWithFormat:@"%s", __FUNCTION__] type:ALogTypeApi line:__LINE__ desc:(frmt), ## __VA_ARGS__];

NS_ASSUME_NONNULL_END
