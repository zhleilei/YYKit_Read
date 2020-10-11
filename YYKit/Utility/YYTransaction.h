//
//  YYTransaction.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/18.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 使您可以在当前运行循环睡眠之前执行一次方法。
 YYTransaction let you perform a selector once before current runloop sleep.
 */
@interface YYTransaction : NSObject

#warning zll YYTransaction 具体的使用场景?
/**
 Creates and returns a transaction with a specified target and selector.
 创建并返回具有指定目标和选择器的事务。
 
 @param target    A specified target, the target is retained until runloop end.
 @param selector  A selector for target.
 
 @return A new transaction, or nil if an error occurs.
 */
+ (YYTransaction *)transactionWithTarget:(id)target selector:(SEL)selector;

/**
 Commit the trancaction to main runloop.
 
 @discussion It will perform the selector on the target once before main runloop's
 current loop sleep. If the same transaction (same target and same selector) has 
 already commit to runloop in this loop, this method do nothing.
 */
- (void)commit;

@end

NS_ASSUME_NONNULL_END
