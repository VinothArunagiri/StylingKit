/*
 * Copyright 2012-present Pixate, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  PXSVGLoader.h
//  Pixate
//
//  Created by Kevin Lindsey on 6/4/12.
//  Copyright (c) 2012 Pixate, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STKShape.h"

@class PXShapeDocument;

/**
 *  PXSVGLoader is used to load SVG files that have been exported by Adobe Illustrator. This does not support any of the
 *  SVG levels or specfications. As such, this loader is likely to fail when loading SVG files generated by hand or by
 *  other tools.
 */
@interface PXSVGLoader : NSObject <NSXMLParserDelegate>

@property (nonatomic) NSURL *URL;

/**
 *  Create a PXScene by loading the SVG file specified by the given URL
 *
 *  @param URL The URL to load
 */
+ (PXShapeDocument *)loadFromURL:(NSURL *)URL;

/**
 *  Create a PXScene by loading the SVG file specified by the given NSData
 *
 *  @param data The NSData to load
 */
+ (PXShapeDocument *) loadFromData:(NSData *)data;

/**
 *  The class that will be used to load the SVG file.
 */
+ (Class)loaderClass;

/**
 *  The class to use when loading the SVG file. This allows loadFromURL to be used in this class while letting another
 *  class (likely a subclass of this one) to perform the actual processing of the SVG file. This comes into play when a
 *  developer wishes to build upon this class's implementation. A typical use case would be the introduction of a new
 *  element type.
 *
 *  @param class The loader class
 */
+ (void)setLoaderClass:(Class)class;

/**
 *  A convenience method that converts a string value to a float
 *
 *  @param attributeValue The value to process
 */
- (CGFloat)numberFromString:(NSString *)attributeValue;

/**
 *  A convenience method that handles most of the common attributes of a shape, such as its stroke and file, for example
 *
 *  @param attributeDict A dictionary of attribute values to process
 *  @param shape The PXShape to which to apply the attributes
 */
- (void)applyStyles:(NSDictionary *)attributeDict forShape:(STKShape *)shape;

/**
 *  Add the specified shape to the PXScene being generated by this class
 *
 *  @param shape A shape to add to the parse results
 */
- (void)addShape:(STKShape *)shape;

@end
