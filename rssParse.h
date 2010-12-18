#ifndef		__RSSPARSE_H__
# define	__RSSPARSE_H__

#include <QtXml>
#include <Qstring>
#include "rss.h"


class	rssParse : public QXmlDefaultHandler
{
 public:
  rssParse(Qstring);
  virtual ~rssParse(){}
  void	parse();
  bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes);
  bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
 private:
  Qstring	_filename;
  Qstring	_tmpString;
  rss		*_rss;
};

#endif
