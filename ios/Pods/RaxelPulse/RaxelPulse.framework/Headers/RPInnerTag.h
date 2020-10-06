//
//  RPInnerTag.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 12.02.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"
#import "RPTag.h"

/// Contains track info processed by server.
@interface RPInnerTag : NSObject<RPJSONSerializable> {
    
}

/// The country code of address.
@property (copy, nonatomic)   NSString  *tag;

/// The country of address.
@property (copy, nonatomic)   NSString  *type;

/// The county of address.
@property (copy, nonatomic)   NSString  *source;

- (instancetype)initWithTag:(RPTag*)tag;

@end
