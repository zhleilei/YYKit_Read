//
//  YYLabel.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYKit/YYKit.h>)
#import <YYKit/YYTextParser.h>
#import <YYKit/YYTextLayout.h>
#import <YYKit/YYTextAttribute.h>
#else
#import "YYTextParser.h"
#import "YYTextLayout.h"
#import "YYTextAttribute.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_INTERFACE_BUILDER

/**
 The YYLabel class implements a read-only text view.
 
 @discussion The API and behavior is similar to UILabel, but provides more features:
 
 * It supports asynchronous layout and rendering (to avoid blocking UI thread).
 * It extends the CoreText attributes to support more text effects.
 * It allows to add UIImage, UIView and CALayer as text attachments.
 * It allows to add 'highlight' link to some range of text to allow user interact with.
 * It allows to add container path and exclusion paths to control text container's shape.
 * It supports vertical form layout to display CJK text.
 
 *它支持异步布局和呈现（以避免阻塞UI线程）。
  
 *它扩展了CoreText属性以支持更多的文本效果。
  
 *它允许添加UIImage，UIView和CALayer作为文本附件。
  
 *它允许在某些文本范围内添加“突出显示”链接，以允许用户进行交互。
  
 *它允许添加容器路径和排除路径来控制文本容器的形状。
  
 *支持垂直表单布局以显示CJK文本。
 
 See NSAttributedString+YYText.h for more convenience methods to set the attributes.
 See YYTextAttribute.h and YYTextLayout.h for more information.
 */
@interface YYLabel : UIView <NSCoding>

#pragma mark - Accessing the Text Attributes
///=============================================================================
/// @name Accessing the Text Attributes
///=============================================================================

/**
 The text displayed by the label. Default is nil.
 Set a new value to this property also replaces the text in `attributedText`.
 Get the value returns the plain text in `attributedText`.
 */
@property (nullable, nonatomic, copy) NSString *text;

/**
 The font of the text. Default is 17-point system font.
 Set a new value to this property also causes the new font to be applied to the entire `attributedText`.
 Get the value returns the font at the head of `attributedText`.
 */
@property (null_resettable, nonatomic, strong) UIFont *font;

/**
 The color of the text. Default is black.
 Set a new value to this property also causes the new color to be applied to the entire `attributedText`.
 Get the value returns the color at the head of `attributedText`.
 */
@property (null_resettable, nonatomic, strong) UIColor *textColor;

/**
 The shadow color of the text. Default is nil.
 Set a new value to this property also causes the shadow color to be applied to the entire `attributedText`.
 Get the value returns the shadow color at the head of `attributedText`.
 */
@property (nullable, nonatomic, strong) UIColor *shadowColor;

/**
 The shadow offset of the text. Default is CGSizeZero.
 Set a new value to this property also causes the shadow offset to be applied to the entire `attributedText`.
 Get the value returns the shadow offset at the head of `attributedText`.
 */
@property (nonatomic) CGSize shadowOffset;

/**
 The shadow blur of the text. Default is 0.
 Set a new value to this property also causes the shadow blur to be applied to the entire `attributedText`.
 Get the value returns the shadow blur at the head of `attributedText`.
 */
@property (nonatomic) CGFloat shadowBlurRadius; // 阴影模糊半径

/**
 The technique to use for aligning the text. Default is NSTextAlignmentNatural.
 Set a new value to this property also causes the new alignment to be applied to the entire `attributedText`.
 Get the value returns the alignment at the head of `attributedText`.
 */
@property (nonatomic) NSTextAlignment textAlignment;

/**
 The text vertical aligmnent in container. Default is YYTextVerticalAlignmentCenter.
 */
@property (nonatomic) YYTextVerticalAlignment textVerticalAlignment;

/**
 The styled text displayed by the label.
 Set a new value to this property also replaces the value of the `text`, `font`, `textColor`,
 `textAlignment` and other properties in label.
 
 @discussion It only support the attributes declared in CoreText and YYTextAttribute.
 See `NSAttributedString+YYText` for more convenience methods to set the attributes.
 */
@property (nullable, nonatomic, copy) NSAttributedString *attributedText;

/**
 The technique to use for wrapping and truncating the label's text.
 Default is NSLineBreakByTruncatingTail.
 例子: NSLineBreakByTruncatingHead,    // Truncate at head of line: "...wxyz"
 */
@property (nonatomic) NSLineBreakMode lineBreakMode;

/**
 The truncation(截断) token string used when text is truncated(被截断). Default is nil.
 When the value is nil, the label use "…" as default truncation token.
 */
@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;

/**
 The maximum number of lines to use for rendering text. Default value is 1.
 0 means no limit.
 */
@property (nonatomic) NSUInteger numberOfLines;

/**
 When `text` or `attributedText` is changed, the parser will be called to modify the text.
 It can be used to add code highlighting or emoticon replacement to text view. 
 The default value is nil.
 
 当更改“文本”或“属性文本”时，将调用解析器来修改文本。
  
 它可以用于在文本视图中添加代码突出显示或表情符号替换。
  
 缺省值为nil。
 See `YYTextParser` protocol for more information.
 */
#warning zll 应用测试
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;

/**
 The current text layout in text view. It can be used to query the text layout information.
 Set a new value to this property also replaces most properties in this label, such as `text`,
 `color`, `attributedText`, `lineBreakMode`, `textContainerPath`, `exclusionPaths` and so on.
 
 文本视图中的当前文本布局。
 它可用于查询文本布局信息。
  
 为此属性设置一个新值也会替换该标签中的大多数属性，例如`text`，
  
 颜色，属性文本，lineBreakMode，textContainerPath，exclusionPaths等。
 
 */

@property (nullable, nonatomic, strong) YYTextLayout *textLayout;


#pragma mark - Configuring the Text Container
///=============================================================================
/// @name Configuring the Text Container
///=============================================================================

/**
 A UIBezierPath object that specifies the shape of the text frame. Default value is nil.
 
 一个UIBezierPath对象，它指定文本框的形状。
 默认值为零。
 */
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;

/**
 An array of UIBezierPath objects representing(表示)  the exclusion(排除) paths inside the
 receiver's bounding rectangle. Default value is nil.
 
 UIBezierPath对象的数组，表示对象内部的排除路径接收者的边界矩形。
 默认值为零。
 */
@property (nullable, nonatomic, copy) NSArray<UIBezierPath *> *exclusionPaths;

/**
 The inset of the text container's layout area within the text view's content area.
 Default value is UIEdgeInsetsZero.
 内边距
 */
@property (nonatomic) UIEdgeInsets textContainerInset;

/**
 Whether the receiver's layout orientation is vertical form. Default is NO.
 接收器的布局方向是否为垂直形式。默认为“否”。
 It may used to display CJK text.
 */
@property (nonatomic, getter=isVerticalForm) BOOL verticalForm;

/**
 The text line position modifier used to modify the lines' position in layout.
 Default value is nil.
 文本行位置修改器，用于修改布局中行的位置。默认值为零。
 See `YYTextLinePositionModifier` protocol for more information.
 */
#warning zll 应用?
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;

/**
 The debug option to display CoreText layout result.
 The default value is [YYTextDebugOption sharedDebugOption].
 */
#warning zll 应用?
@property (nullable, nonatomic, copy) YYTextDebugOption *debugOption;


#pragma mark - Getting the Layout Constraints
///=============================================================================
/// @name Getting the Layout Constraints
///=============================================================================

/**
 The preferred maximum width (in points) for a multiline label.
 
 多行标签的首选最大宽度（以磅为单位）。
 
 @discussion This property affects the size of the label when layout constraints 
     are applied to it. During layout, if the text extends beyond the width 
     specified by this property, the additional text is flowed to one or more new 
     lines, thereby increasing the height of the label. If the text is vertical 
     form, this value will match to text height.
 */
@property (nonatomic) CGFloat preferredMaxLayoutWidth;


#pragma mark - Interacting with Text Data
///=============================================================================
/// @name Interacting with Text Data
///=============================================================================

/**
 When user tap the label, this action will be called (similar to tap gesture).
 The default value is nil.
 
 文字添加的动作
 */
@property (nullable, nonatomic, copy) YYTextAction textTapAction;

/**
 When user long press the label, this action will be called (similar to long press gesture).
 The default value is nil.
 
 长按
 */
@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;

/**
 When user tap the highlight range of text, this action will be called.
 The default value is nil.
 
 长按高亮
 */
@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;

/**
 When user long press the highlight range of text, this action will be called.
 The default value is nil.
 
 长按高亮
 */
@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;


#pragma mark - Configuring the Display Mode
///=============================================================================
/// @name Configuring the Display Mode 配置显示模式
///=============================================================================

/**
 A Boolean value indicating whether the layout and rendering codes are running
 asynchronously on background threads. 
 
 开启异步显示
 The default value is `NO`.
 */
@property (nonatomic) BOOL displaysAsynchronously;

/**
 If the value is YES, and the layer is rendered asynchronously, then it will
 set label.layer.contents to nil before display. 
 如果值为YES，并且图层是异步渲染的，则它将在显示之前将label.layer.contents设置为nil。
 The default value is `YES`.
 
 @discussion When the asynchronously display is enabled, the layer's content will
 be updated after the background render process finished. If the render process
 can not finished in a vsync time (1/60 second), the old content will be still kept
 for display. You may manually clear the content by set the layer.contents to nil 
 after you update the label's properties, or you can just set this property to YES.
 */
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;

/**
 If the value is YES, and the layer is rendered asynchronously, then it will add 
 a fade animation on layer when the contents of layer changed. 
 
 如果值为YES，并且图层是异步渲染的，则它将添加当图层的内容更改时，图层上的淡入淡出动画。
 The default value is `YES`.
 */
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;

/**
 If the value is YES, then it will add a fade animation on layer when some range
 of text become highlighted. 
 
 The default value is `YES`.
 */
@property (nonatomic) BOOL fadeOnHighlight;

/**
 Ignore common properties (such as text, font, textColor, attributedText...) and
 only use "textLayout" to display content.
 
 忽略常见属性（例如文本，字体，textColor，attributedText ...），然后仅使用“ textLayout”显示内容。
 
 The default value is `NO`.
 
 @discussion If you control the label content only through "textLayout", then
 you may set this value to YES for higher performance.
 */
@property (nonatomic) BOOL ignoreCommonProperties;

/*
 Tips:
 
 1. If you only need a UILabel alternative to display rich text and receive link touch event,
    you do not need to adjust the display mode properties.
 
 2. If you have performance issues, you may enable the asynchronous display mode
    by setting the `displaysAsynchronously` to YES.
 
 3. If you want to get the highest performance, you should do text layout with
    `YYTextLayout` class in background thread. Here's an example:

 1.如果您只需要UILabel替代品即可显示格式文本并接收链接触摸事件，
     
 您不需要调整显示模式属性。
  
  
 2.如果遇到性能问题，可以启用异步显示模式
     
 通过将“ displaysAsynchronously”设置为“ YES”。
  
  
 3.如果要获得最高的性能，则应使用
     
 后台线程中的`YYTextLayout`类。
 这是一个例子：
 
 
    YYLabel *label = [YYLabel new];
    label.displaysAsynchronously = YES;
    label.ignoreCommonProperties = YES;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
 
        // Create attributed string.
        NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"Some Text"];
        text.font = [UIFont systemFontOfSize:16];
        text.color = [UIColor grayColor];
        [text setColor:[UIColor redColor] range:NSMakeRange(0, 4)];
 
        // Create text container
        YYTextContainer *container = [YYTextContainer new];
        container.size = CGSizeMake(100, CGFLOAT_MAX);
        container.maximumNumberOfRows = 0;
        
        // Generate a text layout.
        YYTextLayout *layout = [YYTextLayout layoutWithContainer:container text:text];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            label.size = layout.textBoundingSize;
            label.textLayout = layout;
        });
    });
 
 */

@end
#warning zll IB_DESIGNABLE 使用

#else // TARGET_INTERFACE_BUILDER
IB_DESIGNABLE
@interface YYLabel : UIView <NSCoding>
@property (nullable, nonatomic, copy) IBInspectable NSString *text;
@property (null_resettable, nonatomic, strong) IBInspectable UIColor *textColor;
@property (nullable, nonatomic, strong) IBInspectable NSString *fontName_;
@property (nonatomic) IBInspectable CGFloat fontSize_;
@property (nonatomic) IBInspectable BOOL fontIsBold_;
@property (nonatomic) IBInspectable NSUInteger numberOfLines;
@property (nonatomic) IBInspectable NSInteger lineBreakMode;
@property (nonatomic) IBInspectable CGFloat preferredMaxLayoutWidth;
@property (nonatomic, getter=isVerticalForm) IBInspectable BOOL verticalForm;
@property (nonatomic) IBInspectable NSInteger textAlignment;
@property (nonatomic) IBInspectable NSInteger textVerticalAlignment;
@property (nullable, nonatomic, strong) IBInspectable UIColor *shadowColor;
@property (nonatomic) IBInspectable CGPoint shadowOffset;
@property (nonatomic) IBInspectable CGFloat shadowBlurRadius;
@property (nullable, nonatomic, copy) IBInspectable NSAttributedString *attributedText;
@property (nonatomic) IBInspectable CGFloat insetTop_;
@property (nonatomic) IBInspectable CGFloat insetBottom_;
@property (nonatomic) IBInspectable CGFloat insetLeft_;
@property (nonatomic) IBInspectable CGFloat insetRight_;
@property (nonatomic) IBInspectable BOOL debugEnabled_;

@property (null_resettable, nonatomic, strong) UIFont *font;
@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;
@property (nullable, nonatomic, strong) YYTextLayout *textLayout;
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;
@property (nullable, nonatomic, copy) NSArray<UIBezierPath *> *exclusionPaths;
@property (nonatomic) UIEdgeInsets textContainerInset;
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;
@property (nonnull, nonatomic, copy) YYTextDebugOption *debugOption;
@property (nullable, nonatomic, copy) YYTextAction textTapAction;
@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;
@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;
@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;
@property (nonatomic) BOOL displaysAsynchronously;
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnHighlight;
@property (nonatomic) BOOL ignoreCommonProperties;
@end
#endif // !TARGET_INTERFACE_BUILDER

NS_ASSUME_NONNULL_END
