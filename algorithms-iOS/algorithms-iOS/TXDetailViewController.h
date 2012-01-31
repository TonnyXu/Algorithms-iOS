//
//  TXDetailViewController.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 12/01/11.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TXDetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) Algorithm *detailItem;

@property (strong, nonatomic) IBOutlet UILabel *algorithmNameLabel;
@property (strong, nonatomic) IBOutlet UILabel *algorithmExplanationLabel;
@property (strong, nonatomic) IBOutlet UIWebView *gistViewer;

@end
