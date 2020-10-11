//
//  UIScreen+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 13/4/5.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides extensions for `UIScreen`.
 */
@interface UIScreen (YYAdd)

/**
 Main screen's scale
 
 @return screen's scale
 */
+ (CGFloat)screenScale;

/**
 Returns the bounds of the screen for the current device orientation.
 返回当前设备方向的Bounds。
 @return A rect indicating the bounds of the screen.
 @see    boundsForOrientation:
 */
- (CGRect)currentBounds NS_EXTENSION_UNAVAILABLE_IOS("");

/**
 Returns the bounds of the screen for a given device orientation.
 `UIScreen`'s `bounds` method always returns the bounds of the
 screen of it in the portrait orientation.
 返回给定设备方向的屏幕边界。
 UIScreen`的`bounds`方法总是返回屏幕以纵向显示。
 @param orientation  The orientation to get the screen's bounds.
 @return A rect indicating the bounds of the screen.
 @see  currentBounds
 */
- (CGRect)boundsForOrientation:(UIInterfaceOrientation)orientation;

/**
 The screen's real size in pixel (width is always smaller than height).
 This value may not be very accurate in an unknown device, or simulator.
 e.g. (768,1024)
 
 屏幕的实际大小（以像素为单位）（宽度始终小于高度）。
 */
@property (nonatomic, readonly) CGSize sizeInPixel;

/**
 The screen's PPI.
 This value may not be very accurate in an unknown device, or simulator.
 在未知设备或模拟器中，该值可能不太准确。
 Default value is 96.
 */
@property (nonatomic, readonly) CGFloat pixelsPerInch;

@end

NS_ASSUME_NONNULL_END
