//
//  UIView+MASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASUtilities.h"
#import "MASConstraintMaker.h"
#import "MASViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 *  MAS_VIEW 根据平台不同UIView或者NSView
 */
@interface MAS_VIEW (MASAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
/**
*    返回MASViewAttribute属性 view item都是self
*/
@property (nonatomic, strong, readonly) MASViewAttribute *mas_left;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_top;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_right;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_bottom;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_leading;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_trailing;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_width;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_height;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerX;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerY;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_baseline;

@property (nonatomic, strong, readonly) MASViewAttribute *(^mas_attribute)(NSLayoutAttribute attr);

#if TARGET_OS_IPHONE || TARGET_OS_TV
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_leftMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_rightMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_topMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_bottomMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_leadingMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_trailingMargin;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerXWithinMargins;
/**
 *    返回MASViewAttribute属性 view item都是self
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerYWithinMargins;

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)mas_closestCommonSuperview:(MAS_VIEW *)view;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)mas_makeConstraints:(void(^)(MASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_updateConstraints:(void(^)(MASConstraintMaker *make))block;

/**
 *  之前的约束将被全部移除
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_remakeConstraints:(void(^)(MASConstraintMaker *make))block;

@end
