//
//  UIImage+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 13/4/4.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provide some commen method for `UIImage`.
 Image process is based on CoreGraphic and vImage.
 为UIImage提供一些通用方法。
 图像处理基于CoreGraphic和vImage。
 */
@interface UIImage (YYAdd)

#pragma mark - Create image
///=============================================================================
/// @name Create image
///=============================================================================

/**
 Create an animated image with GIF data. After created, you can access
 the images via property '.images'. If the data is not animated gif, this
 function is same as [UIImage imageWithData:data scale:scale];
 
 使用GIF数据创建动画图像。
 创建后，您可以访问
  
 通过属性“ .images”的图像。
 如果数据不是gif动画，则此

 功能与[UIImage imageWithData：data scale：scale]相同；
 
 @discussion     It has a better display performance, but costs more memory
                 (width * height * frames Bytes). It only suited to display small 
                 gif such as animated emoticon. If you want to display large gif, 
                 see `YYImage`.
 
 @param data     GIF data.
 
 @param scale    The scale factor
 
 @return A new image created from GIF, or nil when an error occurs.
 */
+ (nullable UIImage *)imageWithSmallGIFData:(NSData *)data scale:(CGFloat)scale;

/**
 Whether the data is animated GIF.
 数据是否为GIF动画。
 @param data Image data
 
 @return Returns YES only if the data is gif and contains more than one frame,
         otherwise returns NO.
 */
+ (BOOL)isAnimatedGIFData:(NSData *)data;

/**
 Whether the file in the specified path is GIF.
 指定路径中的文件是否为GIF。
 @param path An absolute file path.
 
 @return Returns YES if the file is gif, otherwise returns NO.
 */
+ (BOOL)isAnimatedGIFFile:(NSString *)path;

/**
 Create an image from a PDF file data or path.
从PDF文件数据或路径创建图像
 
 @discussion If the PDF has multiple page, is just return's the first page's
 content. Image's scale is equal to current screen's scale, size is same as 
 PDF's origin size.
 
 @param dataOrPath PDF data in `NSData`, or PDF file path in `NSString`.
 
 @return A new image create from PDF, or nil when an error occurs.
 */
+ (nullable UIImage *)imageWithPDF:(id)dataOrPath;

/**
 Create an image from a PDF file data or path.
 
 @discussion If the PDF has multiple page, is just return's the first page's
 content. Image's scale is equal to current screen's scale.
 
 @param dataOrPath  PDF data in `NSData`, or PDF file path in `NSString`.
 
 @param size     The new image's size, PDF's content will be stretched as needed.
 新图像的大小，PDF的内容将根据需要进行拉伸。
 
 @return A new image create from PDF, or nil when an error occurs.
 */
+ (nullable UIImage *)imageWithPDF:(id)dataOrPath size:(CGSize)size;

/**
 Create a square image from apple emoji.
 从苹果表情符号创建方形图像。
 
 @discussion It creates a square image from apple emoji, image's scale is equal
 to current screen's scale. The original emoji image in `AppleColorEmoji` font 
 is in size 160*160 px.
 
 它从苹果表情符号创建一个正方形图像，图像的比例等于当前的屏幕比例。
 “ Apple Color Emoji”字体的原始表情符号图片尺寸为160 * 160像素。
 
 @param emoji single emoji, such as @"😄".
 
 @param size  image's size.
 
 @return Image from emoji, or nil when an error occurs.
 */
#warning zll test
+ (nullable UIImage *)imageWithEmoji:(NSString *)emoji size:(CGFloat)size;

/**
 Create and return a 1x1 point size image with the given color.
 
 @param color  The color.
 */
+ (nullable UIImage *)imageWithColor:(UIColor *)color;

/**
 Create and return a pure color image with the given color and size.
 创建并返回具有给定颜色和尺寸的纯彩色图像。
 
 @param color  The color.
 @param size   New image's type.
 */
+ (nullable UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 Create and return an image with custom draw code.
自定义绘制代码创建并返回图像。
 
 @param size      The image size.
 @param drawBlock The draw block.
 
 @return The new image.
 */
+ (nullable UIImage *)imageWithSize:(CGSize)size drawBlock:(void (^)(CGContextRef context))drawBlock;

#pragma mark - Image Info
///=============================================================================
/// @name Image Info
///=============================================================================

/**
 Whether this image has alpha channel.
 此图像是否具有Alpha通道。
 */
- (BOOL)hasAlphaChannel;


#pragma mark - Modify Image
///=============================================================================
/// @name Modify Image  修改图片
///=============================================================================

/**
 Draws the entire image in the specified rectangle, content changed with
 the contentMode.
 在指定的矩形中绘制整个图像，内容更改为 contentMode
 
 @discussion This method draws the entire image in the current graphics context, 
 respecting the image's orientation setting. In the default coordinate system, 
 images are situated down and to the right of the origin of the specified 
 rectangle. This method respects any transforms applied to the current graphics 
 context, however.
 
 @param rect        The rectangle in which to draw the image.
 
 @param contentMode Draw content mode
 
 @param clips       A Boolean value that determines whether content are confined to the rect.
 */
- (void)drawInRect:(CGRect)rect withContentMode:(UIViewContentMode)contentMode clipsToBounds:(BOOL)clips;

/**
 Returns a new image which is scaled from this image.
 The image will be stretched as needed.
 
 返回从该图像缩放的新图像。
 图像将根据需要拉伸。
 
 @param size  The new size to be scaled, values should be positive.
 
 @return      The new image with the given size.
 */
- (nullable UIImage *)imageByResizeToSize:(CGSize)size;

/**
 Returns a new image which is scaled from this image.
 The image content will be changed with thencontentMode.
 
 返回从该图像缩放的新图像。
 图像内容将使用thencontentMode进行更改。
 
 @param size        The new size to be scaled, values should be positive.
 
 @param contentMode The content mode for image content.
 
 @return The new image with the given size.
 */
- (nullable UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

/**
 Returns a new image which is cropped from this image.
 返回从该图像裁剪的新图像。
 
 @param rect  Image's inner rect.
 
 @return      The new image, or nil if an error occurs.
 */
- (nullable UIImage *)imageByCropToRect:(CGRect)rect;

/**
 Returns a new image which is edge inset from this image.
 返回一个新图像，该图像是此图像的边缘插图。
 
 @param insets  Inset (positive) for each of the edges, values can be negative to 'outset'.
 
 @param color   Extend edge's fill color, nil means clear color.
 
 @return        The new image, or nil if an error occurs.
 */
- (nullable UIImage *)imageByInsetEdge:(UIEdgeInsets)insets withColor:(nullable UIColor *)color;

/**
 Rounds a new image with a given corner size.
 用给定的角大小对图片切圆角
 
 @param radius  The radius of each corner oval. Values larger than half the
                rectangle's width or height are clamped appropriately to half
                the width or height.
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius;

/**
 Rounds a new image with a given corner size.
 用给定的角大小对图片切圆角
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.

 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width 
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor;

/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.
 
 @param corners      A bitmask value that identifies the corners that you want
                     rounded. You can use this parameter to round only a subset
                     of the corners of the rectangle.
 
 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width 
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 
 @param borderLineJoin The border line join. 边界线连接
 kCGLineJoinMiter,
 kCGLineJoinRound,
 kCGLineJoinBevel
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                       corners:(UIRectCorner)corners
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor
                                borderLineJoin:(CGLineJoin)borderLineJoin;

/**
 Returns a new rotated image (relative to the center).
 
 @param radians   Rotated radians in counterclockwise.⟲
 
 @param fitSize   YES: new image's size is extend to fit all content.
                  NO: image's size will not change, content may be clipped.
 */
- (nullable UIImage *)imageByRotate:(CGFloat)radians fitSize:(BOOL)fitSize;

/**
 Returns a new image rotated counterclockwise by a quarter‑turn (90°). ⤺
 The width and height will be exchanged.
 */
- (nullable UIImage *)imageByRotateLeft90;

/**
 Returns a new image rotated clockwise by a quarter‑turn (90°). ⤼
 The width and height will be exchanged.
 */
- (nullable UIImage *)imageByRotateRight90;

/**
 Returns a new image rotated 180° . ↻
 */
- (nullable UIImage *)imageByRotate180;

/**
 Returns a vertically flipped image. ⥯ 上下翻转
 */
- (nullable UIImage *)imageByFlipVertical;

/**
 Returns a horizontally flipped image. ⇋ 左右翻转
 */
- (nullable UIImage *)imageByFlipHorizontal;


#pragma mark - Image Effect
///=============================================================================
/// @name Image Effect
///=============================================================================

/**
 Tint the image in alpha channel with the given color.
 
 使用给定的颜色在alpha通道中着色图像。 https://www.jianshu.com/p/9ae8c5911d14
 
 @param color  The color.
 */
- (nullable UIImage *)imageByTintColor:(UIColor *)color;

/**
 Returns a grayscaled image.
 返回灰度图像。
 */
- (nullable UIImage *)imageByGrayscale;

/**
 Applies a blur effect to this image. Suitable for blur any content.
 对图像应用模糊效果。
 适用于模糊任何内容。
 */
- (nullable UIImage *)imageByBlurSoft;

/**
 Applies a blur effect to this image. Suitable for blur any content except pure white.
 (same as iOS Control Panel)
 */
- (nullable UIImage *)imageByBlurLight;

/**
 Applies a blur effect to this image. Suitable for displaying black text.
 (same as iOS Navigation Bar White)
 对图像应用模糊效果。
 适用于显示黑色文本。
  
 （与iOS导航栏白色相同）
 */
- (nullable UIImage *)imageByBlurExtraLight;

/**
 Applies a blur effect to this image. Suitable for displaying white text.
 (same as iOS Notification Center)
 对图像应用模糊效果。
 适用于显示白色文本。
  
 （与iOS通知中心相同）
 */
- (nullable UIImage *)imageByBlurDark;

/**
 Applies a blur and tint color to this image.
 将模糊和色调颜色应用于此图像。
 @param tintColor  The tint color.
 */
#warning zll 场景??
- (nullable UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

/**
 Applies a blur, tint color, and saturation adjustment to this image,
 optionally within the area specified by @a maskImage.
 将模糊，色彩和饱和度调整应用于此图像，
  
 （可选）在@a maskImage指定的区域内。
 
 @param blurRadius     The radius of the blur in points, 0 means no blur effect.
 
 @param tintColor      An optional UIColor object that is uniformly blended with
                       the result of the blur and saturation operations. The
                       alpha channel of this color determines how strong the
                       tint is. nil means no tint.
 
 @param tintBlendMode  The @a tintColor blend mode. Default is kCGBlendModeNormal (0). 混合模式
 
 @param saturation     A value of 1.0 produces no change in the resulting image.
                       Values less than 1.0 will desaturation the resulting image
                       while values greater than 1.0 will have the opposite effect.
                       0 means gray scale.
 
 饱和
 
 值为1.0不会在生成的图像中产生任何变化。
                        
 小于1.0的值将使生成的图像去饱和
                        
 而值大于1.0则会产生相反的效果。
                        
 0表示灰度。
 
 @param maskImage      If specified, @a inputImage is only modified in the area(s)
                       defined by this mask.  This must be an image mask or it
                       must meet the requirements of the mask parameter of
                       CGContextClipToMask.
 
 @return               image with effect, or nil if an error occurs (e.g. no
                       enough memory).
 */
- (nullable UIImage *)imageByBlurRadius:(CGFloat)blurRadius
                              tintColor:(nullable UIColor *)tintColor
                               tintMode:(CGBlendMode)tintBlendMode
                             saturation:(CGFloat)saturation
                              maskImage:(nullable UIImage *)maskImage;

@end

NS_ASSUME_NONNULL_END
