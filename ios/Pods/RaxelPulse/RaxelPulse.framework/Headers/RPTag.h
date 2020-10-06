//
//  RPTag.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 13.03.2020.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"

@interface RPTag : NSObject<RPJSONSerializable> {
    
}

/// The country code of address.
@property (copy, nonatomic)   NSString  *tag;

/// The county of address.
@property (copy, nonatomic)   NSString  *source;

@end
