#include <stdio.h>
#include <stddef.h>
#include <assert.h>

enum bool { TRUE=1, FALSE=0} BOOL;

typedef struct { // Shape 物件，沒有欄位
} Shape;

typedef struct { // Shape 類別，有一個 area() 函數
  int (*area)(Shape*); // 第一個參數永遠是該物件
} ShapeClass;

int ShapeArea(Shape *obj);

ShapeClass shapeClass = {
  .area = ShapeArea
};

int ShapeArea(Shape *obj) {
  printf("&ShapeObject=%p &shapeClass=%p\n", obj, &shapeClass);
  assert(FALSE);
}

int main() {
  Shape s;
  ShapeArea(&s);
}

