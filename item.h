#ifndef		__ITEM_H__
# define	__ITEM_H__

#include <Qstring>

class	item
{
 public:
  item();
  virtual ~item();
  
  void		setTitle(Qstring);
  void		setDescription(Qstring);
  void		setLink(Qstring);
  void		setPubDate(Qstring);
  void		setAuthor(Qstring);
  void		setCategory(Qstring);
  void		setComments(Qstring);

  Qstring	getTitle() const;
  Qstring	getDescription() const;
  Qstring	getLink() const;
  Qstring	getPubDate() const;
  Qstring	getAuthor() const;
  Qstring	getCategory() const;
  Qstring	getComments() const;

 private:
  // obligatoire
  Qstring	_title;
  Qstring	_description;
  // optionnel
  Qstring	_link;
  Qstring	_pubDate;
  Qstring	_author;
  Qstring	_category;
  Qstring	_comments;
};

#endif
