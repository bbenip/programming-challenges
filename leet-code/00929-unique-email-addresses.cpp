class Solution {
  public:
    int numUniqueEmails(vector<string>& emails) {
      unordered_set<string> uniqueEmails;

      for (const auto& email : emails) {
        const int delimeterIndex = email.find('@');

        const string localNameRaw = email.substr(0, delimeterIndex);
        const string domainName = email.substr(
          delimeterIndex + 1,
          string::npos
        );

        string localName = "";

        for (const auto& ch : localNameRaw) {
          if (ch == '+') {
            break;
          }

          if (ch == '.') {
            continue;
          }

          localName += ch;
        }

        const string parsedEmail = localName + '@' + domainName;
        uniqueEmails.insert(parsedEmail);
      }

      return uniqueEmails.size();
    }
};
