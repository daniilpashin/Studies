//SimpleTestCase

#import <XCTest/XCTest.h>
#import "string.h"

@interface SimpleTestCase : XCTestCase

@end


char *concat_numbers(const double *numbers, const size_t size, size_t *out_size);
char *normalize_line(const char *line, const size_t size, size_t *out_size);

@implementation SimpleTestCase

- (void)testLineConcate
{
    double numbers[] = {
        0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 32.0, 32.5762
    };
    
    size_t out_size = 0;
    char *string = concat_numbers(numbers, 10, &out_size);
    XCTAssert(string != NULL);
    
    printf("\n%s\n\n", string);
    free(string);
}

- (void)testLineNormalizing
{
    const char *line = "0.0 1.0 2.0 3.0 4.0 5.0 6.0 7.0 32.0 32.5762";
    
    size_t out_size = 0;
    char *normalized = normalize_line(line, strlen(line), &out_size);
    XCTAssert(normalized != NULL);

    printf("\n%s\n\n", normalized);
    free(normalized);
}

@end
