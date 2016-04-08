//
//  MASAttribute.h
//  Masonry
//
//  Created by Jonas Budelmann on 21/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASUtilities.h"

/**
 *  An immutable tuple which stores the view and the related NSLayoutAttribute.
 *  Describes part of either the left or right hand side of a constraint equation
 *  保存view item NSLayoutAttribute三个属性
 */
@interface MASViewAttribute : NSObject

/**
 *  The view which the reciever relates to. Can be nil if item is not a view.
 *  item不是view时可以为空
 */
@property (nonatomic, weak, readonly) MAS_VIEW *view;

/**
 *  The item which the reciever relates to.
 */
@property (nonatomic, weak, readonly) id item;

/**
 *  The attribute which the reciever relates to
 */
@property (nonatomic, assign, readonly) NSLayoutAttribute layoutAttribute;

/**
 *  Convenience initializer. 默认item为view
 */
- (id)initWithView:(MAS_VIEW *)view layoutAttribute:(NSLayoutAttribute)layoutAttribute;

/**
 *  The designated initializer.
 */
- (id)initWithView:(MAS_VIEW *)view item:(id)item layoutAttribute:(NSLayoutAttribute)layoutAttribute;

/**
 *	Determine whether the layoutAttribute is a size attribute
 *
 *	@return	YES if layoutAttribute is equal to NSLayoutAttributeWidth or NSLayoutAttributeHeight
 */
- (BOOL)isSizeAttribute;

@end
