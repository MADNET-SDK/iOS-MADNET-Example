//
//  MADSize.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef struct MADSize
{
    CGSize size;
    NSUInteger flags;
} MADSize;

#pragma mark Basic Sizes

extern MADSize const kmAdSize_120x20;
extern MADSize const kmAdSize_120x30;

extern MADSize const kmAdSize_168x28;
extern MADSize const kmAdSize_168x42;

extern MADSize const kmAdSize_216x36;
extern MADSize const kmAdSize_216x54;

extern MADSize const kmAdSize_320x50;
extern MADSize const kmAdSize_300x50;
extern MADSize const kmAdSize_300x75;

extern MADSize const kmAdSize_300x250;

extern MADSize const kmAdSize_468x60;
extern MADSize const kmAdSize_728x90;
extern MADSize const kmAdSize_120x600;
extern MADSize const kmAdSize_160x600;

#pragma mark Custom Sizes
MADSize mAdSizeFromCGSize(CGSize aSize);
NSString *madSize2String(MADSize aSize);

