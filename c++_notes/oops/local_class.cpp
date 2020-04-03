/*
 *
 * A class declared inside function .
 *
 *              void fun(){
 *                  class Test{
 *
 *                  };
 *              }
 *
 *
 *
 *      Intersting facts
 *      
 *      1.  can only be used in the enclosing function
 *
 *      2.  all the methodes  of local class must be defined inside the class only.
 *              it can't be defined using Class_name::function type .
 *
 *      3.  it can not contain static data members , but it can contain static function members
 *
 *      4.  member methode of local class can only access static and enum varibales of the enclosing function.
 *          non-static varibale of the enclosing function are not accessible inside  local classes.
 *
 *      5.
