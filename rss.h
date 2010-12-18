#ifndef		__RSS_H__
# define	__RSS_H__

#include <Qstring>
#include "item.h"

class	rss
{
 public:
  rss(Qstring);
  ~rss();
  
  void		setVersion(Qstring);
  void		setTitle(Qstring);
  void		setDescription(Qstring);
  void		setLink(Qstring);
  void		setPubDate(Qstring);
  void		setLastBuildDate(Qstring);
  void		setImage(Qstring);
  void		setLanguage(Qstring);

  Qstring	getVersion() const;
  Qstring	getTitle() const;
  Qstring	getDescription() const;
  Qstring	getLink() const;
  Qstring	getPubDate() const;
  Qstring	getLastBuiltDate() const;
  Qstring	getImage() const;
  Qstring	getLanguage() const;

  bool		verifValid() const;
  item		*_items[10];
 private:
  // obligatoire
  Qstring	_version;
  Qstring	_title;
  Qstring	_link;
  Qstring	_description;
  bool		_metaVersion;
  bool		_metaTitle;
  bool		_metaLink;
  bool		_metaDesc;
  // optionnel
  Qstring	_pubDate;
  Qstring	_lastBuiltDate;
  Qstring	_image;
  Qstring	_language;

  int		_nbItem;
};

#endif
