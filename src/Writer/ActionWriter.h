#ifndef ACTION_WRITER_H
#define ACTION_WRITER_H

/*!
 * \file ActionWriter.h
 */

#include <string>

class ActionWriter {
 private:
  std::string statement_;
  std::string result_;

 public:
  ActionWriter(const std::string& statement, const std::string& result);

  void updateStatement(const std::string& statement) { statement_ = statement; }
  void updateResult(const std::string& result) { result_ = result; }

  const std::string& statement() const { return statement_; }
  const std::string& result() const { return result_; }

  void writeStatement() const;
  void writeResult() const;
};

#endif