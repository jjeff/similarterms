<?php
// $Id $
/**
 * @file
 * Provide node nid argument handler.
 */

/**
 * Argument handler to accept a node id.
 * basically identical node_handler_argument_node_nid except that it doesn't
 * add a where clause to the query
 */
class similarstuff_handler_argument_node_nid extends views_handler_argument_numeric {
  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title_query() {
    $titles = array();
    $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));

    $result = db_query("SELECT n.title FROM {node} n WHERE n.nid IN ($placeholders)", $this->value);
    while ($term = db_fetch_object($result)) {
      $titles[] = check_plain($term->title);
    }
    return $titles;
  }
  
  function query() {
    /*
    $this->ensure_my_table();

    if (!empty($this->options['break_phrase'])) {
      views_break_phrase($this->argument, $this);
    }
    else {
      $this->value = array($this->argument);
    }

    if (count($this->value) > 1) {
      $operator = empty($this->options['not']) ? 'IN' : 'NOT IN';
      $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));
      $this->query->add_where(0, "$this->table_alias.$this->real_field $operator ($placeholders)", $this->value);
    }
    else {
      $operator = empty($this->options['not']) ? '=' : '!=';
      $this->query->add_where(0, "$this->table_alias.$this->real_field $operator %d", $this->argument);
    }
    */
  }
  
}