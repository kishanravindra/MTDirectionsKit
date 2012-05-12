//
//  MTDDirectionsRequest.h
//  MTDirectionsKit
//
//  Created by Matthias Tretter on 21.01.12.
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


#import "MTDDirectionsRouteType.h"
#import "MTDDirectionsDefines.h"
#import "MTDHTTPRequest.h"


/**
 An instance of MTDDirectionsRequest is used to retreive information about a route from a given fromCoordinate
 to a given toCoordinate. MTDDirectionsRequest itself cannot be instantiated and must be subclassed.
 */
@interface MTDDirectionsRequest : NSObject

/******************************************
 @name Route
 ******************************************/

/** the start coordinate of the route to request */
@property (nonatomic, assign) CLLocationCoordinate2D fromCoordinate;
/** the end coordinate of the route to request */
@property (nonatomic, assign) CLLocationCoordinate2D toCoordinate;
/** the block that gets executed once the request is finished */
@property (nonatomic, copy) mtd_direction_block completion;
/** the type of the route to request */
@property (nonatomic, assign) MTDDirectionsRouteType routeType;

/******************************************
 @name Lifecycle
 ******************************************/

/**
 This method is used to create a request from a given fromCoordinate to a given toCoordinate with a specified routeType.
 
 @param fromCoordinate the start coordinate of the route to request
 @param toCoordinate the end coordinate of the route to request
 @param routeType the type of the route to request
 @param completion the block to execute when the request is finished
 */
+ (id)requestFrom:(CLLocationCoordinate2D)fromCoordinate
               to:(CLLocationCoordinate2D)toCoordinate
        routeType:(MTDDirectionsRouteType)routeType
       completion:(mtd_direction_block)completion;

/**
 This method is used to create a request from a given fromCoordinate to a given toCoordinate.
 It calls requestFrom:to:routeType:completion: with the routeType specified in the define
 kMTDDefaultDirectionsRouteType in the file MTDDirectionsRouteType.h.
 
 @param fromCoordinate the start coordinate of the route to request
 @param toCoordinate the end coordinate of the route to request
 @param completion the block to execute when the request is finished
 */
+ (id)requestFrom:(CLLocationCoordinate2D)fromCoordinate
               to:(CLLocationCoordinate2D)toCoordinate
       completion:(mtd_direction_block)completion;

/**
 The designated initializer used to instantiate an MTDDirectionsRequest.
 
 @param fromCoordinate the starting coordinate of the route to request
 @param toCoordinate the end coordinate of the route to request
 @param routeType the type of route to request
 @param completion block that is executed when requesting of the route is finished
 */
- (id)initFrom:(CLLocationCoordinate2D)fromCoordinate
            to:(CLLocationCoordinate2D)toCoordinate
     routeType:(MTDDirectionsRouteType)routeType
    completion:(mtd_direction_block)completion;

/******************************************
 @name Request
 ******************************************/

/** Starts the request */
- (void)start;
/** Cancels a possible ongoing request, does nothing if the request isn't active. */
- (void)cancel;

@end