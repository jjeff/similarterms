Similar By Terms module for Drupal
by Jeff Robbins / Lullabot
---------------------------------------

This module was written as a reimplementation of the Similar By Terms (http://drupal.org/project/similarterms) module which I originally wrote for Drupal 5. The module creates lists of nodes sorted by their similarity to a given node based on commonality of taxonomy terms. However, Similar By Terms uses Views to create its database queries and display its results. This means that you can define what fields to show, additional sorting, filters, displays, etc. Super flexible!

Usage: ---------------------------------
There is an example default view called "Similar By Terms". I recommend cloning this view as a starting spot for  most uses.

The simplest way to set things up is to add a free tagging vocabulary to the nodes which you'd like to show similarity and then add a bunch (more than 3, less than 20) terms to your content. Then enable the "Similar By Terms" block on the page. Ta da!

- Similar to what? First off, Similar By Terms needs to know what node it is going to show stuff similar to. This is done through the "Arguments" section of the Views interface. Adding "Similar By Terms: Nid" here will allow you to pass in a node id. You can usually set this to 'Provide default argument' > 'Node ID from URL' if you want to show a block on the same page as a node, or a tab on the node page.

- Similar By Terms's magic happens in the "Sort criteria". Simply add "Similar By Terms: Count of similar terms" as your first sort criteria and results will be sorted by similarity to the node given as an argument to the view. You may also want to provide secondary sorting, so that nodes with the same number of common terms are sorted either alphabetically, or by date.

- There's also a field titled "Similar By Terms: Similarity" which shows the commonality between the terms associated with the listed nodes and those of the node being passed in as an argument. This can be output either as a percentage (recommended), or as a raw count of the number of terms which the nodes have in common.

Keep in mind that the more terms used, the better for finding similarity. However, more terms will create slower database queries. Be sure to cache blocks and Views output where possible.

Example: -------------------------------

Given node (passed as argument):
  Node 1
    Terms: A, B, C, D, E, F
    (6 terms total)
  
Results:
  Node 2
    Terms: [B, C, D, E, F,] G
    (5 terms in common with given = similarity 83%)
  Node 3
    Terms: [A, B, C, D, E,] H
    (5 terms in common  = similarity 83%)
  Node 4
    Terms: [B, C, D, F,] I, J, K, L, M
    (4 terms in common = similarity 67%)
  Node 5
    Terms: [A, B, C]
    (3 terms in common = similarity 50%)
  Node 6
    Terms: [A, B,] J, K, L, M, N, O, P, Q
    (2 terms in common = similarity 33%)
    
    
@todo
  - Rename the module to Similar By Terms 2
  - Perhaps impose some reasonable limit on the number of tids which could/should be used a query
  