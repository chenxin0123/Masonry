//
//  MASConstraintBuilder.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASConstraint.h"
#import "MASUtilities.h"
//M
typedef NS_OPTIONS(NSInteger, MASAttribute) {
    MASAttributeLeft = 1 << NSLayoutAttributeLeft,
    MASAttributeRight = 1 << NSLayoutAttributeRight,
    MASAttributeTop = 1 << NSLayoutAttributeTop,
    MASAttributeBottom = 1 << NSLayoutAttributeBottom,
    MASAttributeLeading = 1 << NSLayoutAttributeLeading,
    MASAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    MASAttributeWidth = 1 << NSLayoutAttributeWidth,
    MASAttributeHeight = 1 << NSLayoutAttributeHeight,
    MASAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    MASAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    MASAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if TARGET_OS_IPHONE || TARGET_OS_TV
    
    MASAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    MASAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    MASAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    MASAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    MASAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    MASAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    MASAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    MASAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface MASConstraintMaker : NSObject

/**
 *	The following properties return a new MASViewConstraint
 *  with the first item set to the makers associated view and the appropriate MASViewAttribute
 */
/**
*  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
*  firstViewAttribute的view item都是self.view
*/
@property (nonatomic, strong, readonly) MASConstraint *left;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *top;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *right;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *bottom;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *leading;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *trailing;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *width;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *height;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *centerX;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *centerY;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *baseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *leftMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *rightMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *topMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *bottomMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *leadingMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *trailingMargin;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *centerXWithinMargins;
/**
 *  添加并返回一个只含一个firstViewAttribute的MASViewConstraint约束
 *  firstViewAttribute的view item都是self.view
 */
@property (nonatomic, strong, readonly) MASConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new MASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  MASAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) MASConstraint *(^attributes)(MASAttribute attrs);

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeEdges
 *  which generates the appropriate MASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *edges;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeSize
 *  which generates the appropriate MASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *size;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeCenter
 *  which generates the appropriate MASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstrait are created with this view as the first item
 *
 *	@return	a new MASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (MASConstraint * (^)(dispatch_block_t))group;

@end
