#ifndef		__RSS_H__
# define	__RSS_H__

#include <string>
#include "item.h"

class	rss
{
 public:
  rss();
  ~rss();
  
  void		setTitle(std::string);
  void		setDescription(std::string);
  void		setLink(std::string);
  void		setPubDate(std::string);
  void		setLastBuildDate(std::string);
  void		setImage(std::string);
  void		setLanguage(std::string);

  std::string	getTitle() const;
  std::string	getDescription() const;
  std::string	getLink() const;
  std::string	getPubDate() const;
  std::string	getLastBuildDate() const;
  std::string	getImage() const;
  std::string	getLanguage() const;

  bool		verifValid() const;
  item		*_items[10];
  int		_nbItem;
 private:
  // obligatoire
  std::string	_title;
  std::string	_link;
  std::string	_description;
  bool		_metaTitle;
  bool		_metaLink;
  bool		_metaDesc;
  // optionnel
  std::string	_pubDate;
  std::string	_lastBuildDate;
  std::string	_image;
  std::string	_language;
};

#endif
