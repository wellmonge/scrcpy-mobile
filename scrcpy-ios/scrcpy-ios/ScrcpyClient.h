//
//  ScrcpyClient.h
//  scrcpy-ios
//
//  Created by Ethan on 2022/6/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ScrcpySharedClient      [ScrcpyClient sharedClient]

@interface ScrcpyClient : NSObject
// ADB Setup
@property (nonatomic, assign)   NSInteger   adbDaemonPort;
@property (nonatomic, copy)     NSString    *adbHomePath;

// ADB Callbacks
@property (nonatomic, copy) void (^onADBConnected)(NSString *serial);
@property (nonatomic, copy) void (^onADBUnauthorized)(NSString *serial);
@property (nonatomic, copy) void (^onADBDisconnected)(NSString *serial);

// Scrcpy Callbacks
@property (nonatomic, copy) void (^onScrcpyConnected)(NSString *serial);
@property (nonatomic, copy) void (^onScrcpyConnectFailed)(NSString *serial);
@property (nonatomic, copy) void (^onScrcpyDisconnected)(NSString *serial);

// Shared instance
+(instancetype)sharedClient;

// ADB trace log
-(void)enableADBVerbose;

// Start scrcpy
-(void)startWith:(NSString *)adbHost adbPort:(NSString *)adbPort options:(NSArray *)scrcpyOptions;

// Stop scrcpy
-(void)stopScrcpy;

@end

NS_ASSUME_NONNULL_END