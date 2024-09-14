#include <iostream>

// 1: periódico
// 2: abierto
// 		1: frio (0)
// 		2: caliente(1)
// 3: Reflejo

#ifndef __BORDER__
#define __BORDER__

class Border {
 public:
	Border(const int kBorder = 1, const int kOpen_type = 1) {
		border_type_ = kBorder;
		open_type_ = kOpen_type;
	}

	int GetBorderType() { return border_type_; }
	int GetOpenType() { return open_type_; }

 private:
 int border_type_{1};
 int open_type_{1};

};

#endif