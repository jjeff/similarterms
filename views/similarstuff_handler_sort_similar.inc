<?php

class similarstuff_handler_sort_similar extends views_handler_sort {
  
  function option_definition() {
    $options = parent::option_definition();

    $options['order'] = array('default' => 'DESC');

    return $options;
  }

  function query() {
    /*
    global $db_type;
    switch ($db_type) {
      case 'mysql':
      case 'mysqli':
        $formula = 'RAND()';
        break;
      case 'pgsql':
        $formula = 'RANDOM()';
        break;
    }
    if (!empty($formula)) {
      $this->query->add_orderby(NULL, $formula, $this->options['order'], '_' . $this->field);
    }
    */
    
    //dsm($this->view->argument['nid']);
  
    //$nid = $this->view->argument['nid']->value[0];
    
    //$nid = $this->view->args[0];
    
    //$tids = array_keys(taxonomy_node_get_terms(node_load($nid)));
    //if (count($tids)) {
      //$placeholders = implode(', ', array_fill(0, count($tids), '%d'));
    //}
    //else {
      //$placeholders = '';
    //}
    
    // @todo: if there are no terms, don't run a query
    
    //dsm($this);
    
    //if (count($tids)) {
      //$this->query->add_table('term_node');
      
    // add function to count nid occurrences based on grouping 
    $this->query->add_field(NULL, 'COUNT(node.nid)', 'node_count', array('aggregate' => TRUE));
    
    //$this->query->add_where(0, "term_node.tid IN ($placeholders)", $tids);
    
    // exclude the current node
    //$this->query->add_where(0, 'node.nid != %d', $nid);
    
    // sort 'em
    $this->query->add_orderby('node', 'count', $this->options['order']); // kludgey
    
    // group 'em
    $this->query->add_groupby('nid');
                
    //$nid = $this->view->args[$this->view->argument['nid']]
    //dsm($this->query);
    
    //$this->query->add_orderby()
    
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    //$form['order']['#access'] = FALSE;
  }
}
