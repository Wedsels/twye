#include "common.hpp"

#include <cstddef>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>

struct TrieCor {
    struct Node {
        Node* chain = 0;
        std::map<char, Node*> queue;

        std::pair<std::string, std::string> string = { "", "" };
    };
    
    std::deque<Node> nodes;
    Node* core;
    
    TrieCor() {
        nodes.resize( 1 );
        core = &nodes[0];
    }
    
    void initialize( std::vector<std::pair<std::string, std::string>>& strs ) {
        for ( int i=0; i<( int )strs.size(); i++ ) {
            std::string &str = strs[i].first;
            Node* node = core;

            for ( char c : str ) {
                if ( node->queue.count( c ) == 0 ) {
                    nodes.push_back( Node() );
                    node->queue[c] = &nodes.back();
                }
                node = node->queue[c];
            }

            auto& string = node->string;
            if ( string.first == "" )
                string = strs[i];
            else
                string.second.replace( string.second.find( string.first ), string.first.size(), strs[i].second );
        }
        
        std::vector<Node*> front;
        for ( std::pair<char, Node*> code : core->queue ) {
            code.second->chain = core;
            front.push_back( code.second );
        }

        for ( int i=0; i<(int)front.size(); i++ ) {
            Node* node = front[i];

            for ( std::pair<char, Node*> code : node->queue ) {
                char c = code.first;

                Node* next = code.second;
                Node* chain = node->chain;
                
                while( chain != 0 && chain->queue.count( c ) == 0 ) chain = chain->chain;
                
                if( chain == 0 ) chain = core;
                else chain = chain->queue[c];
                
                next->chain = chain;
                front.push_back( next );
            }
        }
    }
    
    std::pair<std::pair<std::string, size_t>, std::set<std::string>> process( std::string& str ) {
        std::set<std::string> gathered = {};

        std::string replaced = str;

        Node* node = core;

        size_t index = 0;
        size_t offset = 0;

        for( char c : str ) {
            while ( node != 0 && node->queue.count( c ) == 0 ) node = node->chain;

            if ( node == 0 ) node = core;
            else node = node->queue[c];
            
            auto string = node->string;
            if ( string.first != "" ) {
                size_t size = string.first.size();
                replaced.replace(  index - size + 1 + offset, size, string.second  );
                offset += string.second.size() - size;

                gathered.emplace( string.first );
            }

            index++;
        }
        
        return { { replaced, replaced.size() }, gathered };
    }
};

std::pair<std::string, size_t> common::aho::replacetext( std::string content, std::vector<std::pair<std::string, std::string>> pattern, std::set<std::string> careful ) {
    TrieCor trie;
    trie.initialize( pattern );

    auto val = trie.process( content );

    for ( auto i : pattern )
        if ( !val.second.contains( i.first ) && !careful.contains( i.first ) )
            common::write( L"failed to replace\n\"", i.first.c_str(), "\"" );

    return val.first;
}