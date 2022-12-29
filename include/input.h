#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
// using namespace std;

/**
 * @todo
 * make it easy to test with various kinds of inputs
*/
class Input
{
public:
    Input() = default;
};

class InputBOJ : public Input
{
public:
    InputBOJ() = default;
};

class InputCodeforces : public Input
{
public:
    InputCodeforces() = default;
};

#endif // INPUT_H