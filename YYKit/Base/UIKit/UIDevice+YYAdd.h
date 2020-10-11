//
//  UIDevice+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 13/4/3.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides extensions for `UIDevice`.
 */
@interface UIDevice (YYAdd)


#pragma mark - Device Information
///=============================================================================
/// @name Device Information
///=============================================================================

/// Device system version (e.g. 8.1)
+ (double)systemVersion;

/// Whether the device is iPad/iPad mini.
@property (nonatomic, readonly) BOOL isPad;

/// Whether the device is a simulator.
@property (nonatomic, readonly) BOOL isSimulator;

/// Whether the device is jailbroken.
@property (nonatomic, readonly) BOOL isJailbroken;

/// Wherher the device can make phone calls.
@property (nonatomic, readonly) BOOL canMakePhoneCalls NS_EXTENSION_UNAVAILABLE_IOS("");

/// The device's machine model.  e.g. "iPhone6,1" "iPad4,6"
/// @see http://theiphonewiki.com/wiki/Models
/// 设备版本信息 "iPhone6,1" "iPad4,6"
@property (nullable, nonatomic, readonly) NSString *machineModel;

/// The device's machine model name. e.g. "iPhone 5s" "iPad mini 2"
/// @see http://theiphonewiki.com/wiki/Models
@property (nullable, nonatomic, readonly) NSString *machineModelName;

/// The System's startup time. 系统的启动时间。
@property (nonatomic, readonly) NSDate *systemUptime;


#pragma mark - Network Information
///=============================================================================
/// @name Network Information
///=============================================================================

/// WIFI IP address of this device (can be nil). e.g. @"192.168.1.111"
@property (nullable, nonatomic, readonly) NSString *ipAddressWIFI;

/// Cell IP address of this device (can be nil). e.g. @"10.2.2.222"
@property (nullable, nonatomic, readonly) NSString *ipAddressCell;


/**
 Network traffic type: 网络流量类型
 
 WWAN: Wireless Wide Area Network.
       For example: 3G/4G.
 
 WIFI: Wi-Fi.
 
 AWDL: Apple Wireless Direct Link (peer-to-peer connection).
       For exmaple: AirDrop, AirPlay, GameKit.
 Apple Wireless Direct Link（对等连接）。
 例如：AirDrop，AirPlay，GameKit。
 */
typedef NS_OPTIONS(NSUInteger, YYNetworkTrafficType) {
    YYNetworkTrafficTypeWWANSent     = 1 << 0,
    YYNetworkTrafficTypeWWANReceived = 1 << 1,
    YYNetworkTrafficTypeWIFISent     = 1 << 2,
    YYNetworkTrafficTypeWIFIReceived = 1 << 3,
    YYNetworkTrafficTypeAWDLSent     = 1 << 4,
    YYNetworkTrafficTypeAWDLReceived = 1 << 5,
    
    YYNetworkTrafficTypeWWAN = YYNetworkTrafficTypeWWANSent | YYNetworkTrafficTypeWWANReceived,
    YYNetworkTrafficTypeWIFI = YYNetworkTrafficTypeWIFISent | YYNetworkTrafficTypeWIFIReceived,
    YYNetworkTrafficTypeAWDL = YYNetworkTrafficTypeAWDLSent | YYNetworkTrafficTypeAWDLReceived,
    
    YYNetworkTrafficTypeALL = YYNetworkTrafficTypeWWAN |
                              YYNetworkTrafficTypeWIFI |
                              YYNetworkTrafficTypeAWDL,
};

/**
 Get device network traffic bytes. 获取设备网络流量字节。
 
 @discussion This is a counter since the device's last boot time.
 Usage:
 
     uint64_t bytes = [[UIDevice currentDevice] getNetworkTrafficBytes:YYNetworkTrafficTypeALL];
     NSTimeInterval time = CACurrentMediaTime();
     
     uint64_t bytesPerSecond = (bytes - _lastBytes) / (time - _lastTime);
     
     _lastBytes = bytes;
     _lastTime = time;
 
 
 @param types traffic types
 @return bytes counter.
 */
- (uint64_t)getNetworkTrafficBytes:(YYNetworkTrafficType)types;


#pragma mark - Disk Space
///=============================================================================
/// @name Disk Space
///=============================================================================

/// Total disk space in byte. (-1 when error occurs) 总磁盘空间（以字节为单位）。
@property (nonatomic, readonly) int64_t diskSpace;

/// Free disk space in byte. (-1 when error occurs) 可用磁盘空间（以字节为单位）。（发生错误时为-1）
@property (nonatomic, readonly) int64_t diskSpaceFree;

/// Used disk space in byte. (-1 when error occurs)  已用磁盘空间（以字节为单位）。（发生错误时为-1）
@property (nonatomic, readonly) int64_t diskSpaceUsed;


#pragma mark - Memory Information
///=============================================================================
/// @name Memory Information
///=============================================================================

/// Total physical memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryTotal;

/// Used (active + inactive + wired) memory in byte. (-1 when error occurs)已用（活动+非活动+有线）内存，以字节为单位。（发生错误时为-1）
@property (nonatomic, readonly) int64_t memoryUsed;

/// Free memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryFree;

/// Acvite memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryActive;

/// Inactive memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryInactive;

/// Wired memory in byte. (-1 when error occurs)
/// 该内存中的信息无法移至硬盘，因此必须保留在RAM中。有线内存的数量取决于您使用的应用程序。
/// 联动内存（Wired Memory）中的内容必须保留在内存中而不能被移动到磁盘或其他外部存储中，这部分内存的大小取决于你正在使用的应用程序
@property (nonatomic, readonly) int64_t memoryWired;

/// Purgable memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryPurgable;

#pragma mark - CPU Information
///=============================================================================
/// @name CPU Information
///=============================================================================

/// Avaliable CPU processor count.
@property (nonatomic, readonly) NSUInteger cpuCount;

/// Current CPU usage, 1.0 means 100%. (-1 when error occurs)
@property (nonatomic, readonly) float cpuUsage;

/// Current CPU usage per processor (array of NSNumber), 1.0 means 100%. (nil when error occurs)
/// 当前每个处理器的CPU使用率（NSNumber数组），1.0表示100％。（发生错误时为零）
@property (nullable, nonatomic, readonly) NSArray<NSNumber *> *cpuUsagePerProcessor;

@end

NS_ASSUME_NONNULL_END


#ifndef kSystemVersion
#define kSystemVersion [UIDevice systemVersion]
#endif

#ifndef kiOS6Later
#define kiOS6Later (kSystemVersion >= 6)
#endif

#ifndef kiOS7Later
#define kiOS7Later (kSystemVersion >= 7)
#endif

#ifndef kiOS8Later
#define kiOS8Later (kSystemVersion >= 8)
#endif

#ifndef kiOS9Later
#define kiOS9Later (kSystemVersion >= 9)
#endif
