//
//  MADSize.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <UIKit/UIKit.h>
/*
 Структура - размер рекламного контейнера
 */
typedef struct MADSize
{
    CGSize size;
    NSUInteger flags;
} MADSize;

#pragma mark Basic Sizes
/*
 Поддерживаемые размеры контейнеров
 */
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
/*
 С использвоанием метода mAdSizeFromCGSize
 предоставляется возможность создать custom размер
 баннер.
 
 @param size - Размер баннера по выбору пользователя
 */
MADSize mAdSizeFromCGSize(CGSize size);

