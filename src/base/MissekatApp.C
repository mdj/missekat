#include "MissekatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MissekatApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MissekatApp::MissekatApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MissekatApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MissekatApp::associateSyntax(_syntax, _action_factory);
}

MissekatApp::~MissekatApp()
{
}

// External entry point for dynamic application loading
extern "C" void MissekatApp__registerApps() { MissekatApp::registerApps(); }
void
MissekatApp::registerApps()
{
  registerApp(MissekatApp);
}

// External entry point for dynamic object registration
extern "C" void MissekatApp__registerObjects(Factory & factory) { MissekatApp::registerObjects(factory); }
void
MissekatApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MissekatApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MissekatApp::associateSyntax(syntax, action_factory); }
void
MissekatApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
