#ifndef MISSEKATAPP_H
#define MISSEKATAPP_H

#include "MooseApp.h"

class MissekatApp;

template<>
InputParameters validParams<MissekatApp>();

class MissekatApp : public MooseApp
{
public:
  MissekatApp(InputParameters parameters);
  virtual ~MissekatApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MISSEKATAPP_H */
