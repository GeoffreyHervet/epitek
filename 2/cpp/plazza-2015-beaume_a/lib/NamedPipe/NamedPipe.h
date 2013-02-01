#ifndef NAMEDPIPE_H_
# define NAMEDPIPE_H_

# include		<string>

/*!
 * \class NamedPipe
 * \brief A simple class for using named pipes on C++
 * \author Geoffrey HERVET
 * \version 1.0
 */

class NamedPipe
{
  public:
    /*!
     * \class Error
     * \brief Exception class of NamedPipe
     */
    class Error : public std::exception
    {
      const char  *_what; /*!< Content of exception */
      public:
        /*!
         * \brief Constructor of Error
         * \param what Error message
         */
        Error(const char *what) throw() : _what(what){};
 
        /*!
         * \brief Getter of message error
         * \return Message error
         */
        const char *what() const throw() { return this->_what; };
    };

  public:
    /*!
     * \brief Constructor wich create fifo file in /tmp/{pid}
     */

    NamedPipe();

    /*!
     * \brief Constructor wich create fifo file
     * \param path Full path of the file wich was CREATED
     */
    NamedPipe(const char *path);
    
    /*!
     * \brief Destructeur wich close the fd
     */
    ~NamedPipe();
    
    /*!
     * \brief Copy constructor NOT IMPLEMENTED
     */
    NamedPipe(const NamedPipe &);
    
    /*!
     * \brief Copy constructor NOT IMPLEMENTED
     */
    NamedPipe		&operator =(const NamedPipe &);

    /*!
     * \brief Write a string into the fifo file
     * \param str The string wicht will write in file
     */
    void		_write(const std::string &str) const;

    /*!
     * \brief Write an integer into the fifo file
     * \param i The integer wicht will write in file
     */
    void		_write(int i) const;

    /*!
     * \brief Read an integer into the fifo file
     * \return The integer wicht will read in file
     */
    int			_read(void) const;

    /*!
     * \brief Read a string into the fifo file
     * \param str The pointer wich will be fill
     * \param size Max size of string
     */
    void		_read(char *str, size_t size) const;

  private:
    int			_fd; /*!< File descriptor of fifo file */
};

NamedPipe		&operator <<(NamedPipe &, const std::string &);

#endif /* NAMEDPIPE_H_ */
