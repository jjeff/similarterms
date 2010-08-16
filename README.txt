Similar Stuff module for Drupal
by Jeff Robbins / Lullabot
---------------------------------------

This module was written as a reimplementation of the Similar By Terms (http://drupal.org/project/similarterms) module which I originally wrote for Drupal 5. The module creates lists of nodes sorted by their similarity to a given node based on commonality of taxonomy terms. However, Similar Stuff uses Views to create its database queries and display its results. This means that you can define what fields to show, additional sorting, filters, displays, etc. Super flexible!

Usage: ---------------------------------
There is an example default view called "Similar stuff". I recommend cloning this view as a starting spot for  most uses.

The simplest way to set things up is to add a free tagging vocabulary to the nodes which you'd like to show similarity and then add a bunch (more than 3, less than 20) terms to your content. Then enable the "Similar stuff" block on the page. Ta da!

- Similar to what? First off, Similar Stuff needs to know what node it is going to show stuff similar to. This is done through the "Arguments" section of the Views interface. Adding "Similar stuff: Nid" here will allow you to pass in a node id. You can usually set this to 'Provide default argument' > 'Node ID from URL' if you want to show a block on the same page as a node, or a tab on the node page.

- Similar Stuff's magic happens in the "Sort criteria". Simply add "Similar stuff: Count of similar terms" as your first sort criteria and results will be sorted by similarity to the node given as an argument to the view. You may also want to provide secondary sorting, so that nodes with the same number of common terms are sorted either alphabetically, or by date.

- For testing purposes, there's also a field titled "Similar stuff: Count of similar terms" which shows a count of similar terms for the the listed node.

Keep in mind that the more terms used, the better for finding similarity. However, more nodes will generate slower queries. Be sure to cache blocks and Views output where possible.

Example: -------------------------------

Given node:
  Node 1
    Terms: A, B, C, D, E, F
  
Results:
  Node 2
    Terms: [B, C, D, E, F,] G
    (5 terms in common with given)
  Node 3
    Terms: [A, B, C, D, E,] H
    (5 terms in common)
  Node 4
    Terms: [B, C, D, F,] I, J, K, L, M
    (4 terms in common)
  Node 5
    Terms: [A, B, C]
    (3 terms in common)
  Node 6
    Terms: [A, B,] J, K, L, M, N, O, P, Q
    (2 terms in common)
    
    
@todo
  - Come up with a better name for the module
  - Move the generation of tids to the arguments section
  - Allow limiting to specific vocabularies
  - Allow passing in of tids through arguments
  - Allow passing in of multiple nodes
  - Add "don't show this node in results" checkbox to nid argument section
  - Create a displayable field which shows the % of similarity rather than count
  - Perhaps impose some reasonable limit on the number of tids which could/should be used a query
  