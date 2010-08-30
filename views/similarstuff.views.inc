<?php
// $Id$

/**
 * @file Similar Stuff Views data include file
 */

function similarstuff_views_data() {
  
  // Basic table information.
  $data['similarstuff']['table']['group']  = t('Similar stuff');

  // what's this do?
  $data['similarstuff']['table']['join'] = array(
    '#global' => array(),
  );
  
  $data['similarstuff']['similarstuff'] = array(
    'title' => t('Similarity'),
    'help' => t('Percentage/count of terms which node has in common with node given as argument.'),
    'field' => array(
      'handler' => 'similarstuff_handler_field_similar',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'similarstuff_handler_sort_similar',
    ),
  );
  
  // nid
  $data['similarstuff']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('ID of content item(s). Passes term ids to Similar Stuff.'), // The help that appears on the UI,
    
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'similarstuff_handler_argument_node_nid',
      'parent' => 'views_handler_argument_numeric', // make sure parent is included
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),

  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function similarstuff_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'similarstuff') . '/views',
    ),
    'handlers' => array(
      'similarstuff_handler_sort_similar' => array(
        'parent' => 'views_handler_sort',
      ),
      'similarstuff_handler_argument_node_nid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'similarstuff_handler_field_similar' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
