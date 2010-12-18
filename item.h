#ifndef		__ITEM_H__
# define	__ITEM_H__

#include <string>

class	item
{
 public:
  item();
  virtual ~item();
  
  void		setTitle(std::string);
  void		setDescription(std::string);
  void		setLink(std::string);
  void		setPubDate(std::string);
  void		setAuthor(std::string);
  void		setCategory(std::string);
  void		setComments(std::string);

  std::string	getTitle() const;
  std::string	getDescription() const;
  std::string	getLink() const;
  std::string	getPubDate() const;
  std::string	getAuthor() const;
  std::string	getCategory() const;
  std::string	getComments() const;

 private:
  // obligatoire
  std::string	_title;
  std::string	_description;
  // optionnel
  std::string	_link;
  std::string	_pubDate;
  std::string	_author;
  std::string	_category;
  std::string	_comments;
};

#endif
