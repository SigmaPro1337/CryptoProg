#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

int main() {
    CryptoPP::SHA256 hash;
    CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
    CryptoPP::FileSource("test", true,
                         new CryptoPP::HashFilter(hash,
                             new CryptoPP::ArraySink(digest, sizeof(digest))));
    std::string hashString;
    CryptoPP::StringSource(digest, sizeof(digest), true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hashString)));
    CryptoPP::StringSource(hashString, true, new CryptoPP::FileSink("result"));
    return 0;
}