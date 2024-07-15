class ParentClass
{
public:
  ParentClass() {};
  virtual void overrideMe() = 0; // pure virtual function
  // virtual void overrideMe() {}; // no problem
};

class ChildClass : public ParentClass
{
public:
  ChildClass() {};
  void overrideMe()
  {
    // do something
  }
};

int main()
{
  ChildClass thing;
}