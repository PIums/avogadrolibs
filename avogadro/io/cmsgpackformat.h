/******************************************************************************
  This source file is part of the Avogadro project.
  This source code is released under the 3-Clause BSD License, (see "LICENSE").
******************************************************************************/

#ifndef AVOGADRO_IO_CMSGPACKFORMAT_H
#define AVOGADRO_IO_CMSGPACKFORMAT_H

#include "fileformat.h"
#include "cjsonformat.h"

namespace Avogadro {
namespace Core {
class GaussianSet;
}
namespace Io {

/**
 * @class CMsgPackFormat cmsgpackformat.h <avogadro/io/cmsgpackformat.h>
 * @brief Implementation of the Chemical MessagePack format.
 */

class AVOGADROIO_EXPORT CMsgPackFormat : public CjsonFormat
{
public:
  CMsgPackFormat();
  ~CMsgPackFormat() override;

  Operations supportedOperations() const override
  {
    return ReadWrite | File | Stream | String;
  }

  FileFormat* newInstance() const override { return new CMsgPackFormat; }
  std::string identifier() const override { return "Avogadro: CMsgPack"; }
  std::string name() const override { return "Chemical MessagePack"; }
  std::string description() const override
  {
    return "CMsgPack format is a lightweight intermediate format used to exchange "
           "information between Avogadro and other data parsing applications";
  }

  std::string specificationUrl() const override
  {
    return "https://github.com/openchemistry/chemicaljson";
  }

  std::vector<std::string> fileExtensions() const override;
  std::vector<std::string> mimeTypes() const override;

  // write MessagePack
  bool m_json = false;
};

} // end Io namespace
} // end Avogadro namespace

#endif // AVOGADRO_IO_CMSGPACKFORMAT_H
