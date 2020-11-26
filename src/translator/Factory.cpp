#include "translator/Factory.h"

// List of exported translator.
TranslatorPtr FrameTranslator();
TranslatorPtr MathTranslator();
TranslatorPtr PlanarGraphTranslator();
TranslatorPtr SequenceTranslator();
TranslatorPtr TableTranslator();
TranslatorPtr TreeTranslator();
TranslatorPtr GrammarTranslator();

std::vector<TranslatorPtr>& TranslatorList() {
  static std::vector<TranslatorPtr> out;
  if (out.size() != 0)
    return out;

  out.push_back(MathTranslator());
  out.push_back(SequenceTranslator());
  out.push_back(TreeTranslator());
  out.push_back(TableTranslator());
  out.push_back(GrammarTranslator());
  out.push_back(FrameTranslator());
  out.push_back(PlanarGraphTranslator());
  return out;
}

Translator* FindTranslator(const std::string& name) {
  auto& list = TranslatorList();
  for (auto& it : list) {
    if (it->Identifier() == name)
      return it.get();
  }
  return nullptr;
}
