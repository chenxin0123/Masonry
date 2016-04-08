//
//  MASExampleOneViewController.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <UIKit/UIKit.h>

///除了一个MASExampleLayoutGuideViewController 例子所有的视图都是使用这个视图控制器
@interface MASExampleViewController : UIViewController

/**
 *  初始化视图控制器
 *
 *  @param title     导航栏镖旗
 *  @param viewClass 类
 */
- (id)initWithTitle:(NSString *)title viewClass:(Class)viewClass;

@end
