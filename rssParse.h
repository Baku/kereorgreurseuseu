#ifndef		__RSSPARSE_H__
# define	__RSSPARSE_H__

#include <vector>
#include <string>
#include "rss.h"


class	rssParse
{
 public:
  rssParse(std::string);
  virtual ~rssParse();
  void	parse();
  std::vector<std::string>	splitString(std::string src, std::string sep);

  rss		*_rss;
 private:
  rssParse();
  std::string	_filename;
  std::string	_tmpString;
  bool		_isItem;
};

#endif
