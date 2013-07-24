//
//  MadNetStyleConfig.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Перечисление стандартных тем для интерфейса встроенного браузера и контроллера изображения.
 */
typedef enum
{
    etsBlack = 0,
    etsBlackTranslucent = 1
} EMadNetToolbarStyle;

/**
 Класс содержит настройки интерфейса встроенного браузера и контроллера изображения.
 */
@interface MadNetStyleConfig : NSObject

/**
 Тема UIToolbar.
 */
@property (nonatomic, assign) UIBarStyle toolbarStyle;
/**
 Базовый цвет UIToolbar.
 */
@property (nonatomic, retain) UIColor *toolbarTintColor;
/**
 Прозрачность UIToolbar.
 */
@property (nonatomic, assign) BOOL toolbarTranslucent;
/**
 Базовый цвет UIBarButtonItem.
 */
@property (nonatomic, retain) UIColor *barButtonItemTintColor;

/**
 Метод применяет одну из стандартных тем к элементам встроенного браузера и контроллера изображения.
 @param aStyle - тема интерфейса. 
 Может принимать два значения:
 etsBlack (применяет к следующим свойствам соответствующие значения):
 toolbarTintColor (nil), toolbarStyle (UIBarStyleBlack), toolbarTranslucent (NO), barButtonItemTintColor ([UIColor grayColor]);
 etsBlackTranslucent (применяет к следующим свойствам соответствующие значения):
 toolbarTintColor (nil), toolbarStyle (UIBarStyleBlack), toolbarTranslucent (YES), barButtonItemTintColor ([UIColor grayColor]).
 */
- (void) setMadNetToolbarStyle: (EMadNetToolbarStyle) aStyle;

/**
 Статический конструктор.
 @return Сущность для настройки интерфейса встроенного браузера и контроллера изображения.
 */
+ (MadNetStyleConfig *) sharedConfig;

@end
